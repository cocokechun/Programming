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
        //cin >> T[i] >> F[i];
        scanf("%d %d", &T[i], &F[i]);
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
            if (j > 0) {
                for (int k = 1; k <= (i-j); k++) { // number of tasks in last slot
                        if (k >= 2) { //with previous slot
                            dp[i][j][k] = dp[i-1][j][k-1] + ((j+1)*S+T[i]) * (F[i]-F[i-1]) +
                                        (T[i] - T[i-1]) * (F[i] - F[i-k]-(F[i]-F[i-1]));
                            /*if (i == 3 && j == 1 && k == 2) {
                                printf("dp[2][1][1] is %d, T[3] is %d, T[2] is %d, F[3] is %d, F[2] is %d\n", dp[2][1][1], T[3], T[2], F[3], F[2]);
                            }*/
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

    /*for (int i = 1; i <= n; i++) { // number of tasks
        cout << i << endl;
        for (int j = 0; j < i; j++) { // number of slots
            cout << j << endl;
            for (int k = 1; k <= i; k++) { // number of tasks in last slot
                cout << dp[i][j][k] << ' ';
            }
            cout << endl;
        }
        cout << '\n' << endl;
    }
    printf("dp[2][1][1] is %d\n", dp[2][1][1]);*/

    int res = MAX;
    for (int j = 0; j < n; j++) {
        res = min(res, mins[n][j]);
    }

    cout << res << endl;
}
