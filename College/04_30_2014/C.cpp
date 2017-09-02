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

int main() {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;
    if (n == 1) {
        cout << a << endl;
        return 0;
    }

    int a2, b2, c2;
    cin >> a2 >> b2 >> c2;
    int gg = b + b2;
    int gc = a;
    int cg = a2;
    int cc = 0; 
    int cc1, gc1, gg1, cg1;
    for (int i = 2; i < n; i++) {
        a = a2;
        b = b2;
        c = c2;
        cin >> a2 >> b2 >> c2;
        cc1 = max(cc, gc);
        gc1 = max(gg, cg);
        gg1 = max(gg-b+c2+b2, cg-a+b2+b2);
        cg1 = max(cc+b2, gc+a2);

        cc = cc1;
        gc = gc1;
        gg = gg1;
        cg = cg1;
    }

    int res = max(cc, max(gc, max(gg, cg)));
    cout << res << endl;
    return 0;
}
