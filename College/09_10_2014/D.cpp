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
#include <limits>
#include <string.h>

using namespace std;
typedef long long ll;
#define MAX 105
char grid[MAX][MAX];
int n, m;
bool visited[MAX][MAX][16];

typedef struct Node {
    int row;
    int col;
    int state;
    int step;
    Node(int a, int b, int c, int d): row(a), col(b), state(c), step(d) {}
} Node;

bool is_valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void solve() {
    memset(grid, 0, MAX * MAX);
    memset(visited, 0, MAX * MAX * 16);
    int start_row;
    int start_col;
    bool has_exit = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '*') {
                start_row = i;
                start_col = j;
            }
            if (grid[i][j] == 'X') {
                has_exit = true;
            }
        }
    }

    if (!has_exit) {
        cout << "The poor student is trapped!" << endl;
        return;
    }

    queue<Node> q;
    q.push(Node(start_row, start_col, 0, 0));
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (visited[cur.row][cur.col][cur.state] || (grid[cur.row][cur.col] == '#')) {
            continue;
        }

        visited[cur.row][cur.col][cur.state] = true;
        char c = grid[cur.row][cur.col];
        if (c == 'X') {
            cout << "Escape possible in " << cur.step << " steps." << endl;
            return;
        }
        if ((c == 'R') && ((cur.state & 1) == 0)) {
            continue;
        }

        if (c == 'G' && ((cur.state & 2) == 0)) {
            continue;
        }

        if (c == 'B' && ((cur.state & 4) == 0)) {
            continue;
        }

        if (c == 'Y' && ((cur.state & 8) == 0)) {
            continue;
        }

        int state2 = cur.state;
        if (c == 'r') {
            state2 |= 1;
        }
        if (c == 'g') {
            state2 |= 2;
        }
        if (c == 'b') {
            state2 |= 4;
        }
        if (c == 'y') {
            state2 |= 8;
        }

        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if ((i == 0 || j == 0) && !(i == 0 && j == 0)) {
                    if (is_valid(cur.row+i, cur.col+j)) {
                        q.push(Node(cur.row+i, cur.col+j, state2, cur.step+1));
                    }
                }
            }
        }
    }

    cout << "The poor student is trapped!" << endl;
    return;
}

int main() {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve();
    }

    return 0;
}

