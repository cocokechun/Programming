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

using namespace std;
typedef pair<int, int> pint;

#define MAX_SIZE 1000

int n;
char grid[MAX_SIZE][MAX_SIZE];
long long ans[MAX_SIZE][MAX_SIZE];

int search() {
    queue<pint> q;
    int visited[n][n];
    memset(visited, 0, n*n*sizeof(int));

    pint start = make_pair(0, 0);
    pint target = make_pair(n-1, n-1);
    q.push(start);
    visited[0][0] = 1;

    while (!q.empty()) {
        pint cur = q.front();
        q.pop();

        if (cur == target) {
            return 1;
        }

        vector<pint> nexts;
        nexts.push_back(make_pair(cur.first, cur.second-1));
        nexts.push_back(make_pair(cur.first, cur.second+1));
        nexts.push_back(make_pair(cur.first-1, cur.second));
        nexts.push_back(make_pair(cur.first+1, cur.second));

        for (int i = 0; i < 4; i++) {
            pint next = nexts[i];
            if (next.first >= 0 && next.first < n &&
                next.second >= 0  && next.second < n) {
                if (visited[next.first][next.second] == 0
                     && grid[next.first][next.second] != '#') {
                    q.push(next);
                    visited[next.first][next.second] = 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int divisor = (1<<31) - 1;
    char s[10];
    cin.getline(s, 10);
    n = atoi(s);
    memset(grid, 0, MAX_SIZE * MAX_SIZE);
    memset(ans, 0, MAX_SIZE * MAX_SIZE * sizeof(long long));

    for (int i = 0; i < n; i++) {
        cin.getline(grid[i], n+1);
    }

     /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    } */

    ans[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                continue;
            } else {
                if (j-1 >= 0) {
                    ans[i][j] += (ans[i][j-1] % divisor);
                }
                if (i-1 >= 0) {
                    ans[i][j] += (ans[i-1][j] % divisor);
                }
            }
        }
    }

     /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    } */

    if (ans[n-1][n-1] > 0) {
        long long res = ans[n-1][n-1] % divisor;
        cout << res << endl;
    } else {
        if (search()) {
            cout << "THE GAME IS A LIE" << endl;
        } else {
            cout << "INCONCEIVABLE" << endl;
        }

    }
    return 0;
}
