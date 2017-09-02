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
#define MAX 1000
bool primes[MAX * MAX];
int grid[MAX][MAX];

int combine(int a, int b) {
    int tmp = b;

    while (tmp > 0) {
        a *= 10;
        tmp /= 10;
    }
    return a + b;
}

int main() {
    int n;
    cin >> n;
    memset(primes, 1, MAX * MAX);
    memset(grid, 0, MAX * MAX * 4);
    int m = combine(n, n);

    for (int i = 2; i <= m; i++) {
        if (primes[i]) {
            for (int multi = 2; multi * i <= m; multi++) {
                primes[multi * i] = false; 
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num = combine(i,j);
            if (primes[num]) {
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + 1;
            } else {
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
            }
        }
    }

    cout << grid[n][n]-1 << endl;
    return 0;
}
