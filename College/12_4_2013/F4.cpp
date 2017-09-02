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
#include <bitset>
#include <set>
using namespace std;

#define MAX 1005
int t1[MAX];
int t2[MAX];
int t3[2 * MAX];
bool t4[MAX][MAX];

int solve(int n, int m) {
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        t1[i] = num;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        t2[i] = num;
    }

    for (int i = 0; i < n+m; i++) {
        scanf("%d", &num);
        t3[i] = num;
    }
    
    t4[0][0] = true; 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i != 0) {
                t4[i][j] = (t4[i-1][j] & (t1[i-1] == t3[i+j-1]));
            }
            if (j != 0) {
                t4[i][j] |= (t4[i][j-1] & (t2[j-1] == t3[i+j-1]));
            }
        }
    }

    return t4[n][m];
}

int main() {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        } else {
            if (solve(n, m)) {
                cout << "possible" << endl;
            } else {
                cout << "not possible" << endl;
            }
        }
    }
    return 0;
}
