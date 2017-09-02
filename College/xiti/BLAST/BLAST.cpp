#include <iostream>
#include <cstring>

using namespace std;

#define MAX 1<<30
#define MAX_SIZE 2005
int dp[MAX_SIZE][MAX_SIZE];

int main() {
    string a, b;
    int k;

    cin >> a >> b >> k;
    int n = a.size();
    int m = b.size();
    //cout << n << ' ' << m << endl;

    for (int i = 1; i <= n; i++) {  // number of chars matched in a
        for (int j = 1; j <= m; j++) { // number of chars matched in b
            if (i == 1) {
                dp[i][j] = (i + j) * k;
                for (int l = 0; l < j; l++) {
                    dp[i][j] = min(dp[i][j], 
                                    abs(a[i-1] - b[l]) + (j - 1) * k);
                }
            } else if (j == 1) {
                dp[i][j] = (i + j) * k;
                for (int l = 0; l < i; l++) {
                    dp[i][j] = min(dp[i][j], 
                                    abs(a[l] - b[j-1]) + (i - 1) * k);
                }
            } else {
                dp[i][j] = min(k + dp[i-1][j], k + dp[i][j-1]);
                dp[i][j] = min(dp[i][j], abs(a[i-1] - b[j-1])+ dp[i-1][j-1]);
            }
        }
    }

    cout << dp[n][m] << endl;
}
