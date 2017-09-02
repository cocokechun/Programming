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

#define PI 3.14159265
using namespace std;
typedef long long ll;

double convert(int a, int b) {
    if (a > 0 && b >= 0) {
        return atan(b * 1.0 / a) * 180 / PI;
    } else if (a <= 0 && b > 0) {
        if (a == 0) {
            return 90.0;
        }
        return 180 - (atan(b * 1.0 / (-a)) * 180 / PI);
    } else if (a < 0 && b <= 0) {
        return 180 + (atan((-b) * 1.0 / (-a)) * 180 / PI);
    } else {
        if (a == 0) {
            return 270.0;
        }
        return 360 - (atan((-b) * 1.0 / a) * 180 / PI); 
    }
}

int main() {
    int casenum = 0;
    while (1) {
        casenum ++;
        int n, x, y, f;
        cin >> n >> x >> y >> f;
        if (f == 0) {
            break;
        }
        if (n == 0) {
            cout << "Case " << casenum << ": " << 0 << endl;
            continue;
        }

        double angles[n];

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            a = a - x;
            b = b - y;
            angles[i] = convert(a, b);
        }
        sort(angles, angles+n);
        /*for (int i = 0; i < n; i++) {
            cout << angles[i] << ' ';
        }
        cout << endl;*/
        int best = 180;
        for (int i = 0; i < n; i++) {
            double end = angles[i] + f * 1.0;
            int counter = 1;
            for (int j = 1; j < n; j++) {
                // wrap around
                double next;
                if (i + j > n-1) {
                    next = 360.0 + angles[(i+j) % n];
                } else {
                    next = angles[i+j];
                }
                if (next > end) {
                    counter += 1;
                    end = next + f * 1.0;
                }
            }
            if (counter < best) {
                best = counter;
            }
        }
        cout << "Case " << casenum << ": " << best << endl;
    }
    return 0;
}

