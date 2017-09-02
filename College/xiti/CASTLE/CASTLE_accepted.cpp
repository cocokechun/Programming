#include <iostream>

using namespace std;

#define MAX 105
#define MAX2 5100
bool dp[MAX2];
bool dp2[MAX2];
int data[MAX][MAX];
bool results[MAX2]; 

int main() {
    int n;
    cin >> n;
    int shortest = MAX2;
    memset(results, true, MAX2);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < MAX; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == -1) break;
            data[i][j] = tmp;
            sum += tmp;
        }
        if (sum < shortest) shortest = sum;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX && data[i][j] > 0; j++) {
            int len = data[i][j];

            for (int k = 1; k <= shortest; k++) {
                dp2[k] = dp[k]; 
            }

            for (int k = len; k <= shortest; k++) {
                if (k == len) {
                    dp[k] = true;
                } else if (k-len > 0 && dp2[k-len]) {
                    dp[k] = true;
                }
            }
        }

        for (int k = 1; k <= shortest; k++) {
            results[k] &= dp[k];
        }

        memset(dp, 0, MAX2);
    }

    for (int k = shortest; k > 0; k--) {
        if (results[k]) {
            cout << k << endl;
            return 0;
        } 
    }

    cout << 0 << endl;
    return 0;
}
