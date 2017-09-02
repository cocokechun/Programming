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
typedef pair<int, int> pii;
typedef long long ll;
#define MAX 105
#define MOD 1000000

pii A[MAX][MAX][4];
bool visited[MAX][MAX][4];
char grid[MAX][MAX];

int getDir(char c) {
    if (c == 'N') {
        return 0;
    } else if (c == 'E') {
        return 1;
    } else if (c == 'S') {
        return 2;
    } else {
        return 3;
    }
}

bool isOnBoard(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int turnLeft(int a) {
    return (a-1+4) % 4;
}

int turnRight(int a) {
    return (a+1+4) % 4;
}

void makeVector(vector<int> &v, int a, int b, int c) {
    v[0] = a;
    v[1] = b;
    v[2] = c;
}

pii makeDir(int a) {
    if (a == 0) {
        return make_pair(-1, 0);
    } else if (a == 1) {
        return make_pair(0, 1);
    } else if (a == 2) {
        return make_pair(1, 0);
    } else {
        return make_pair(0, -1);
    }
}

void solve(int n, int m) {
    memset(A, 0, MAX * MAX * 4 * sizeof(pii));
    memset(grid, 0, MAX * MAX);
    memset(visited, 0, MAX * MAX * 4);
    vector<int> start(3, 0);

    int erow, ecol;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            //cout << i << ' ' << j << ' ' << grid[i][j] << endl;
            if (grid[i][j] == 'X') {
                erow = i;
                ecol = j;
            } else if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                start[0] = i;
                start[1] = j;
                start[2] = getDir(grid[i][j]);
            }
        }
    }

   queue<vector<int> > q;
   q.push(start);
   A[start[0]][start[1]][start[2]] = make_pair(0, 1);
   visited[start[0]][start[1]][start[2]] = true;
   vector<int> tmp(3, 0);
   
   while (!q.empty()) {
       vector<int> cur = q.front();
       q.pop();
      
       int row = cur[0];
       int col = cur[1];
       /*if (grid[row][col] == 'X') {
           break;
       }*/
       int dir = cur[2]; 
       int left = turnLeft(dir); 
       int right = turnRight(dir);
       int steps = (A[row][col][dir]).first+1;

        // go left
       if (visited[row][col][left]) {
            if (A[row][col][left].first == steps) {
                A[row][col][left].second = 
                (A[row][col][left].second + A[row][col][dir].second) % MOD;

            }
       } else {
            A[row][col][left] = make_pair(steps, A[row][col][dir].second);
            visited[row][col][left] = true;
            makeVector(tmp, row, col, left);
            q.push(tmp);
       }

      // go right
       if (visited[row][col][right]) {
            if (A[row][col][right].first == steps) {
                A[row][col][right].second = 
                (A[row][col][right].second + A[row][col][dir].second) % MOD;
            }
       } else {
            A[row][col][right] = make_pair(steps, A[row][col][dir].second);
            visited[row][col][right] = true;
            makeVector(tmp, row, col, right);
            q.push(tmp);
       }

       // go forward
       pii ddir = makeDir(dir);
       int drow = row+ddir.first; 
       int dcol = col+ddir.second; 
       while(1) {
           if (!isOnBoard(drow, dcol, n, m)) {
               break;
           }
           if (grid[drow][dcol] == '*') {
               break;
           }
           if (visited[drow][dcol][dir]) {
                if (A[drow][dcol][dir].first == steps) {
                A[drow][dcol][dir].second = 
                (A[drow][dcol][dir].second + A[row][col][dir].second) % MOD;
                }
           } else {
                A[drow][dcol][dir] = make_pair(steps, A[row][col][dir].second);
                visited[drow][dcol][dir] = true;
                makeVector(tmp, drow, dcol, dir);
                q.push(tmp);
           }
           drow += ddir.first;
           dcol += ddir.second;
       }
   }

   /*for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           cout << i << ' ' << j << ' '<< A[i][j][0].first << ' ' << A[i][j][1].first << ' ' << A[i][j][2].first << ' ' <<  A[i][j][3].first << endl;
           cout << i << ' ' << j << ' '<< A[i][j][0].second << ' ' << A[i][j][1].second << ' ' << A[i][j][2].second << ' ' <<  A[i][j][3].second << endl;
       }
       cout << endl;
   }*/

   if (visited[erow][ecol][0] ||
       visited[erow][ecol][1] ||
       visited[erow][ecol][2] ||
       visited[erow][ecol][3]
       ) {
        int best = ~(1 << 31);
        for (int i = 0; i < 4; i++) {
            if (visited[erow][ecol][i]) {
                best = min(best, A[erow][ecol][i].first);
            }
        }
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (visited[erow][ecol][i] && A[erow][ecol][i].first == best) {
                count = (count + A[erow][ecol][i].second) % MOD;
            }
        }
        cout << best << ' ' << count << endl;
   } else {
       cout << 0 << ' ' << 0 << endl;
   }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0) return 0;
        solve(n, m);
    }
}

