#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;


int solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        return 0;
    }

    int counter = 0;
    int aa, bb, cc, dd;
    while (true) {
        if (a == b && b == c && c == d) {
            break;
        }
        aa = abs(a-b);
        bb = abs(b-c);
        cc = abs(c-d);
        dd = abs(d-a);
        a = aa;
        b = bb;
        c = cc;
        d = dd;
        counter += 1;
    }
    cout << counter << endl;
    return 1;
}

int main() {
    while (solve());
    return 0;
}
