#include <iostream>
#include <limits>
#include <vector>

using namespace std;
#define MAX numeric_limits<int>::max()
#define MAX_SIZE 5005
int T[MAX_SIZE];
int F[MAX_SIZE];
vector<int> dp[MAX_SIZE][MAX_SIZE];
int mins[MAX_SIZE][MAX_SIZE];

int main() {
    int n, S;
    cin >> n >> S;

    for (int i = 1; i <= n; i++) {
        cin >> T[i] >> F[i];
        T[i] += T[i-1];
        F[i] += F[i-1];
        //cout << T[i] << ' ' << F[i] << endl;
    }

    for (int i = 0; i <= n; i++) {
        for (int k = 0; k <= n; k++) {
            dp[i][k].assign(n+1, 0);
        }
    }

    for (int i = 1; i <= n; i++) { // number of tasks
        for (int j = 0; j < i; j++) { // number of slots
            int best = MAX;
            for (int k = 1; k <= (i-j); k++) { // number of tasks in last slot
                    if (j > 0 && k > 2) {
                        dp[i][j][k] = dp[i-1][j][k-1] + (j*S+T[i]) * (F[i]-F[i-1]) +
                                    (T[i] - T[i-1]) * (F[i] - F[i-k]);
                    } else {
                        dp[i][j][k] = (S+T[i]) * (F[i] - F[0]);
                    }

                    if (k == 1 && j > 0) { // singleton for this slot
                        dp[i][j][k] = min(dp[i][j][k],
                                        mins[i-1][j-1] + (j*S+T[i]) * (F[i]-F[i-1]));
                    }
                best = min(best, dp[i][j][k]);
            }
            mins[i][j] = best;
        }
    }

    for (int i = 1; i <= n; i++) { // number of tasks
        cout << i << endl;
        for (int j = 0; j < i; j++) { // number of slots
            cout << j << endl;
            for (int k = 1; k <= i-j; k++) { // number of tasks in last slot
                cout << dp[i][j][k] << ' ';
            }
            cout << endl;
        }
        cout << '\n' << endl;
    }

    int res = MAX;
    for (int j = 0; j < n; j++) {
        res = min(res, mins[n][j]);
    }

    cout << res << endl;


    
}
