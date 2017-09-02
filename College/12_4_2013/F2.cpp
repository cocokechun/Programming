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

#define MAX 1000005
int t1[MAX];
int t2[MAX];
int t3[2 * MAX];

using namespace std;
typedef long long ll;

int helper(int c, int a, int b, int n, int m) {
    if (c == n+m) {
        return 1;
    }
    if (a < n && t3[c] == t1[a]) {
        if (helper(c+1, a+1, b, n, m)) return 1;
    }
    if (b < m && t3[c] == t2[b]) {
        if (helper(c+1, a, b+1, n, m)) return 1;
    }
    return 0;
}

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
    
    return helper(0, 0, 0, n, m);
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
