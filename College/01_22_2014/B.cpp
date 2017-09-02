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
typedef long long ll;

#define MAX 10005
int data[15];
int dp[15][MAX];

int square(int a) {
    return a * a;
}

int main() {
    int n, m;
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }

    // or memset
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (i * i > m) break;
        dp[1][i*i] = square(i-data[1]);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= 100; k++) {
                int len = data[i];
                if (k*k >= j) break;
                if (dp[i-1][j-k*k] >= 0) {
                    int tmp = dp[i-1][j-k*k] + square(len-k);
                    dp[i][j] = (dp[i][j] == -1) ? (tmp) : min(dp[i][j], tmp);
                }
            }
        }
    }

    cout << dp[n][m] << endl;
}
