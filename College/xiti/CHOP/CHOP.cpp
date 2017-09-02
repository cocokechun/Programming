#include <iostream>

using namespace std;

#define MAX 100
#define MAXMAX 100000000

int dp[MAX][MAX];
int lens[MAX];

int sqr(int a) {
    return a * a;
}

int main() {
    int n, m;

    cin >> n >> m;
    m += 3;

    if (n < 2*m) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> lens[i];
    }

    sort(lens, lens+n);

    for (int k = 1; k <= m; k++) {
        for (int i = 0; i < n; i++) {
            if (k == 1) {
                if (i >= 2*k-1) {
                    dp[k][i] = (i == 1) ? sqr(lens[i]-lens[i-1]) : 
                                        min(dp[k][i-1], sqr(lens[i]-lens[i-1]));
                }
            } else if (i == 2*k-1) {
                dp[k][i] = dp[k-1][i-2] + sqr(lens[i]-lens[i-1]);
            } else if (i > 2*k-1) {
                dp[k][i] = min(dp[k][i-1], 
                                dp[k-1][i-2] + sqr(lens[i]-lens[i-1]));
            }
        }
    }

    int best = MAXMAX;
    for (int i = 2*m-1; i < n; i++) {
        if (dp[m][i] < MAXMAX) {
            best = dp[m][i];
        }
    }

    cout << best << endl;
}
