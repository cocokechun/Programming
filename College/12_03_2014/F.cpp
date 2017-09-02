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
#define MAX 55
int cake[MAX][MAX];
int row_sums[MAX][MAX][MAX];
int sums[MAX][MAX][MAX][MAX]; 
int bests[MAX][MAX][MAX][MAX]; 

int solve(int srow, int scol, int erow, int ecol) {
    if (bests[srow][scol][erow][ecol] > 0) {
        return bests[srow][scol][erow][ecol];
    }
    if (srow == erow && scol == ecol) {
        return 0;
    }

    int best = ~(1<<31);
    int base = sums[srow][scol][erow][ecol];

    // cut horizontally
    for (int i = srow; i < erow; i++) {
        best = min(best, solve(srow, scol, i, ecol)
                         + solve(i+1, scol, erow, ecol)); 
    }

    // cut vertically
    for (int i = scol; i < ecol; i++) {
        best = min(best, solve(srow, scol, erow, i)
                         + solve(srow, i+1, erow, ecol)); 
    }

    bests[srow][scol][erow][ecol] = best + base;
    return best+base;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cake[i][j];
        }
    }

    memset(row_sums, 0, MAX*MAX*MAX*4);
    memset(sums, 0, MAX*MAX*MAX*MAX*4);
    memset(bests, 0, MAX*MAX*MAX*MAX*4);

    // preprocess data so that we know the row_sums of each rectangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // starting point

            // calculate row row_sums
            for (int k = j; k < m; k++) { // ending col
                if (k == j) {
                    row_sums[i][j][k] = cake[i][j];
                } else {
                    row_sums[i][j][k] = cake[i][k] + row_sums[i][j][k-1];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // starting point
            // calculate rectangle row_sums
            for (int k = i; k < n; k++) {
                for (int q = j; q < m; q++) {
                    if (k == i) {
                        sums[i][j][k][q] = row_sums[i][j][q];
                    } else {
                        sums[i][j][k][q] = sums[i][j][k-1][q]+
                                           row_sums[k][j][q];
                    }
                }
            }
        }
    }

    
    cout << solve(0, 0, n-1, m-1) << endl;
    // for printing
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { // starting point
            for (int k = 0; k < n; k++) {
                for (int q = 0; q < m; q++) {
                    cout << bests[i][j][k][q] << ' ';
                }
                cout << endl;
            }

            cout << endl;
        }
    }*/
    return 0;
}
