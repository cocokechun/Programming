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

using namespace std;
#define MAX 1002
typedef unsigned long long ull;

ull dp[MAX];

int main() {
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
   
    for (int k = 4; k < MAX; k++) {
        dp[k] = (1ULL << min(63, k)) - 1;
        for (int i = 1; i < 64; i++) {
            dp[k] = min(dp[k], 2ULL * dp[k-i] + ((1ULL << i) - 1ULL));
        }
    }

    int n;
    int tn = 0;
    while (cin >> n) {
        tn ++;
        printf("Case %d: %llu\n", tn, dp[n]);
    }
}
