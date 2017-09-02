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
#include <deque>

using namespace std;
typedef long long ll;
#define MAX 200005
ll PRIME = 393919;
ll MOD = 10000000000037;
ll A[MAX];
ll B[MAX];
ll diffs[2*MAX];

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A, A+n);
    ll a = 0;
    for (int i = 0; i < n-1; i++) {
        a *= PRIME;
        a %= MOD;
        a += (A[i+1]-A[i]);
        a %= MOD;
    }
    a *= PRIME;
    a %= MOD;
    a += (A[0]+360000-A[n-1]);
    a %= MOD;

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(B, B+n);
    for (int i = 0; i < n-1; i++) {
        diffs[i] = B[i+1] - B[i];
    }
    diffs[n-1] = B[0]+360000-B[n-1];

    for (int i = 0; i < n; i++) {
        diffs[i+n] = diffs[i];
    }

    // for rolling hash
    ll big = 1;
    for (int i = 1; i < n; i++) {
        big *= PRIME;
        big %= MOD;
    }

    ll b = 0;
    for (int i = 0; i < n; i++) {
        b *= PRIME;
        b %= MOD;
        b += diffs[i];
        b %= MOD;
    }

    if (b == a) {
        cout << "possible" << endl;
        return 0;
    }

    for (int i = n; i < 2*n; i++) {
        b += MOD;
        b -= (diffs[i-n] * big) % MOD;
        b %= MOD;
        b *= PRIME;
        b %= MOD;
        b += diffs[i];
        b %= MOD;
        if (b == a) {
            cout << "possible" << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}
