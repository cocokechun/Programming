#include <iostream>

using namespace std;

#define MAX 20
int nums[MAX];
int dp[MAX][MAX][MAX];

int main() {
    int n, K;
    cin >> n >> K;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int gap=0; gap<n; gap++) {
        for (int i=0; i<n;i++) {  // i is start
            int j = i + gap;     // j is end. j <= i
            if (j >= n) {
                continue;
            }
            if (gap == 0) {
                dp[i][j][0] = nums[i];
            } else {
                for (int k = 0; k <= gap; k++) {  // k is number of * in first 
                                                  // half
                    for (int q = i; q < j; q++) {
                        for (int p = 0; p <= k && p <= (q-i); p++) {
                            dp[i][j][k] = max(dp[i][j][k],
                                        dp[i][q][p] + dp[q+1][j][k-p]);
                            if (k > 0 && p < k) {
                                dp[i][j][k] = max(dp[i][j][k],
                                        dp[i][q][p] * dp[q+1][j][k-1-p]);
                            }
                        }
                    }
                }
            }
        }
    }

    int best = dp[0][n-1][K];
    cout << best << endl;
}
