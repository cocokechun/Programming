#include <iostream>
#include <limits>

using namespace std;

#define MAX 10000
int dp[MAX];
int fee[MAX];

int main() {
    int n;
    
    for (int i = 1; i < 11; i++) {
        cin >> fee[i];
    }

    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = numeric_limits<int>::max(); 
        for (int j = 1; j <= min(i, 10); j++) {
            dp[i] = min(dp[i], fee[j] + dp[i-j]); 
        }
    }

    cout << dp[n] << endl;
}
