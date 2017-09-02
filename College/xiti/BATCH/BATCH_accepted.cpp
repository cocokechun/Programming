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
        scanf("%d %d", &T[i], &F[i]);
        T[i] += T[i-1];
        F[i] += F[i-1];
    }

    for (int i = 0; i <= n; i++) {
        for (int k = 0; k <= n; k++) {
            dp[i][k].assign(n+1, 0);
        }
    }

    for (int i = 1; i <= n; i++) { // number of tasks
        for (int j = 0; j < i; j++) { // number of divisors between slots, so it's 1 less
                                      // than number of slots
            int best = MAX;
            if (j > 0) {
                for (int k = 1; k <= (i-j); k++) { // number of tasks in last slot
                        if (k >= 2) { //with previous slot
                            dp[i][j][k] = dp[i-1][j][k-1] + ((j+1)*S+T[i]) * (F[i]-F[i-1]) +
                                        (T[i] - T[i-1]) * (F[i] - F[i-k]-(F[i]-F[i-1]));
                        } else { // singleton slot
                            dp[i][j][k] = mins[i-1][j-1] + ((j+1)*S+T[i]) * (F[i]-F[i-1]);
                        }

                    best = min(best, dp[i][j][k]);
                }
                mins[i][j] = best;
            } else {
                dp[i][j][i] = (S + T[i]) * (F[i] - F[0]);
                mins[i][j] = dp[i][j][i];
            }
        }
    }

    int res = MAX;
    for (int j = 0; j < n; j++) {
        res = min(res, mins[n][j]);
    }

    cout << res << endl;
}
