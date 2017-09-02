#include <iostream>
#include <limits>
#include <stack>

using namespace std;

#define MAX 105
int dp[MAX][MAX];
int groups[MAX][MAX];
int acc_sum[MAX];
int acc_max[MAX];

int main() {
    int n, k, pages, tmp;
    
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> pages;
        acc_sum[i] = acc_sum[i-1] + pages;
        acc_max[i] = max(acc_max[i-1], pages); 
    }

    for (int gap = 0; gap < n; gap++) {
        for (int i = 1; i <= k; i++) { // number of people
            int j = i + gap;          // number of books
            if (j > n) {
                continue;
            } else if (i == 1) {
                dp[i][j] = acc_sum[j]; 
                groups[i][j] = 0; 
            } else if (i == j) {
                dp[i][j] = acc_max[j];
                groups[i][j] = j-1;
            } else {
                dp[i][j] = numeric_limits<int>::max();
                for (int p = j-1; p >= i-1; p--) {
                    tmp = max(dp[i-1][p], acc_sum[j] - acc_sum[p]);
                    if (tmp <= dp[i][j]) {
                        dp[i][j] = tmp;
                        groups[i][j] = p;
                    }
                }
            }
        }
    }

    /*for (int i = 1; i <= k; i++) {
        for (int j = 1; j <=n; j++) {
            cout << dp[i][j] << ' '; 
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <=n; j++) {
            cout << groups[i][j] << ' '; 
        }
        cout << endl;
    }
    cout << endl;*/

    int row = k;
    int col = n;
    int last = n;
    stack<int> s;

    while (row >= 1) {
        s.push(last);
        //printf("pushed %d\n", last);
        last = groups[row][col];
        row -= 1;
        col = last;
    }

    printf("1");
    while (!s.empty()) {
        if (s.top() == n) {
            printf(" %d\n", n);
        } else {
            printf(" %d\n%d", s.top(), s.top()+1);
        }
        s.pop();
    }
}
