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
#define MAX 1005
#define pi (atan(1.0)*4)
double dp[MAX][15];

double findCircleDis(int index, double r, char type, int m) {
    if (type == 'L') {
        index = m-1-index;
    }
    r += (index*10)+5;
    return 0.5*pi*r;
}

double findDis(int from, int to, int len) {
    double vertical = abs(from-to) * 10;
    return sqrt(len*len+vertical*vertical);
}

double solve(int n, int m) {
    char type;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> type >> x;
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                if (type == 'S') {
                    dp[i][j] = x;
                } else {
                    dp[i][j] = findCircleDis(j, x, type, m); 
                }
            } else {
                if (type == 'S') {
                    dp[i][j] = dp[i-1][j] + x; 
                    for (int k = 0; k < m; k++) {
                        if (abs(k-j) <= x/100) {
                            dp[i][j] = min(dp[i][j], 
                                           dp[i-1][k]+findDis(k,j,x));
                        }
                    }
                } else {
                    dp[i][j] = findCircleDis(j, x, type, m) + dp[i-1][j];
                }
            }
        }
    }

    double best = dp[n-1][0];
    for (int j = 0; j < m; j++) {
        best = min(best, dp[n-1][j]);
    }
    return best;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0) {
            break;
        }
        printf("%.2f\n", solve(n,m));
    }
    return 0;
}
