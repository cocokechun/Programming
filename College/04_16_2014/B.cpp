#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>

using namespace std;
typedef long long ll;

#define MAX 10
char G[MAX][MAX];
bool visited[MAX][MAX];
set<int> lefts[MAX][MAX];
int rights[MAX][MAX];

bool is_valid(int row, int col, int n) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

void find_left(int n, int depth, int row, int col, int acc) {
    if (depth < 0) {
        return;
    }
    if (G[row][col] == '(' && !visited[row][col]) {
        lefts[row][col].insert(acc);
        visited[row][col] = true;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                //printf("%d %d\n", i, j);
                if ((i == 0 || j == 0) && !(i == 0 && j == 0)) {
                    if (is_valid(row+i, col+j, n) && G[row+i][col+j] == '(') {
                        find_left(n, depth-1, row+i, col+j, acc+1);
                    }
                }
            }
        }
        visited[row][col] = false;
    }
}

int find_right(int n, int row, int col) {
    if (!visited[row][col]) {
        visited[row][col] = true;
        int res = 0;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                //printf("%d %d\n", i, j);
                if ((i == 0 || j == 0) && !(i == 0 && j == 0)) {
                    if (is_valid(row+i, col+j, n) && G[row+i][col+j] == ')') {
                        res = max(res, 1 + find_right(n, row+i, col+j));
                    }
                }
            }
        }
        visited[row][col] = false;
        return res;
    }
    return 0;
}

int main() {
    string s;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            G[i][j] = s[j];
        }
    }

    memset(visited, 0, MAX * MAX);
    find_left(n, 12, 0, 0, 1);
    memset(rights, 0, MAX * MAX * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == ')') 
                rights[i][j] = find_right(n, i, j);
                //cout << rights[i][j] << ' ';
        }
        //cout << endl;
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "(";
            for (set<int>::iterator it = lefts[i][j].begin(); it != lefts[i][j].end(); 
                    it++) {
                cout << *it << ',';
            }
            cout << ")  ";
        }
        cout << endl;
    }*/

    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int best_right = 0;
            for (int k = -1; k < 2; k++) {
                for (int l = -1; l < 2; l++) {
                    //printf("%d %d\n", i, j);
                    if ((k == 0 || l == 0) && !(k == 0 && l == 0)) {
                        if (is_valid(i+k, j+l, n)) {
                            best_right = max(best_right, rights[i+k][j+l]);
                        }
                    }
                }
            }

            for (set<int>::iterator it = lefts[i][j].begin(); it != lefts[i][j].end();
                it++) {
                if (*it <= best_right) {
                    best = max(best, 2 * (*it));
                }
            }
        }
    }
    cout << best << endl;
}
