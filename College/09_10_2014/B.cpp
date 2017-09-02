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
#include <cstring>

using namespace std;
typedef long long ll;
#define MAX 20
#define INF 400
int n, m;
int grid[MAX][MAX];
int trial[MAX][MAX];
int first[MAX];
int best;

bool is_valid(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < m;
}

void flip(int row, int col) {
    trial[row][col] = 1 - trial[row][col];
    if (is_valid(row-1, col)) {
        trial[row-1][col] = 1 - trial[row-1][col];
    }
    if (is_valid(row+1, col)) {
        trial[row+1][col] = 1 - trial[row+1][col];
    }
    if (is_valid(row, col-1)) {
        trial[row][col-1] = 1 - trial[row][col-1];
    }
    if (is_valid(row, col+1)) {
        trial[row][col+1] = 1 - trial[row][col+1];
    }
}

int count_flip() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            trial[i][j] = grid[i][j];
        }
    }

    // flip the first row, and there're at most 2 ** 16 combinations
    for (int i = 0; i < m; i++) {
        if (first[i]) {
            flip(0,i);
            count++;
        }
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (trial[i][j] == 1) {
                flip(i+1, j); 
                count++;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (trial[n-1][j] == 1) {
            return INF;
        }
    }
    return count;
}

void set_first_row(int col) {
    if (col == m) {
        int tiles = count_flip();
        best = min(tiles, best);
        return;
    }

    for (int i = 0; i < 2; i++) {
        first[col] = i;
        set_first_row(col+1);
    }
}

int main() {
    while (1) {
        cin >> n >> m;
        if( n== 0 && m == 0) break;
        memset(grid, 0, MAX * MAX * 4);
        memset(trial, 0, MAX * MAX * 4);
        memset(first, 0, MAX * 4);

        char c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                grid[i][j] = ((c == 'X') ? 1 : 0);
                //trial[i][j] = grid[i][j];
            }
        }

        best = INF;
        set_first_row(0);
        if (best == INF) {
            cout << "Damaged billboard." << endl;
        } else {
            cout << "You have to tap "  << best << " tiles."<< endl;
        }
    }
}
