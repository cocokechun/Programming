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

int main() {
    int a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;

    int count = 0;
    while (c > a) {
        c --;
        if (b >= x) {
            b -= x;
        } else {
            a = a-1;
            b = w-(x-b);
        }
        count ++;
    }

    cout << count << endl;
}

