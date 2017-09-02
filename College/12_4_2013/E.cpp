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
typedef long long ll;

ll divs(ll b, ll t) {
    ll counter = 0;
    for (ll i = 1; i <= b; i++) {
        if (i * i > b) {
            break;
        } else if (i * i == b && i <= t) {
            counter++;
        } else if (b % i == 0) {
            if (i <= t) counter++;
            if (b/i <= t) counter++;
        }
    }
    return counter;
}

int main() {
    ll n, t, b;
    ll tn = 0;

    while (cin >> n >> t >> b) {
        tn ++;
        t = t % n;
        ll res = divs(b, t); 
        //cout << res << endl;
        if (res % 2 == 1) {
            printf("Case %lld: On\n", tn);
        } else {
            printf("Case %lld: Off\n", tn);
        }
    }
    return 0;
}
