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
#define MAX 505
int nums[MAX];
int products[MAX][MAX];
int dp[MAX][MAX];

void solve(int n, int m) {
    memset(nums, 0, MAX * 4);
    memset(products, 0, MAX * MAX * 4);
    memset(dp, 0, MAX * MAX  * 4);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            if (i == j) {
                products[i][j] = 0;
            } else {
                products[i][j] = products[i][j-1] + sum * nums[j];
            }
            sum += nums[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k <= m; k++) {
            if (k == 0) {
                dp[i][k] = products[0][i];
            } else {
                dp[i][k] = products[0][i];
                for (int q = 0; q <= i-1; q++) {
                    dp[i][k] = min(dp[i][k], dp[q][k-1]+products[q+1][i]);
                }
            }
        }
    }
    cout << dp[n-1][m] << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (!(n == 0 && m == 0)) {
        solve(n, m);
        cin >> n >> m;
    }

    return 0;
}
