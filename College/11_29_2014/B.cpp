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
int xsteps[2005];
int ysteps[2005];
int oldxsteps[2005]; // x fixed
int oldysteps[2005]; // y fixed
#define INF 200000000

int dis(int sx, int sy, int ex, int ey) {
    return abs(ex-sx) + abs(ey-sy);
}

int main() {
    int n;

    cin >> n;
    int lastx = 0;
    int lasty = 0;
    bool start = true;

    int x, y;
    for (int i = 0; i < n; i++ ) {
        cin >> x >> y;
        for (int j = -1000; j <= 1000; j++) {
            if (start) {
                xsteps[j+1000] = dis(0, 0, x, j);
                ysteps[j+1000] = dis(0, 0, j, y);
                start = false;
            } else {
                xsteps[j+1000] = min(oldxsteps[j+1000]+abs(x-lastx), 
                                     oldysteps[1000+x]+abs(y-lasty));
                ysteps[j+1000] = min(oldysteps[j+1000]+abs(y-lasty),
                                     oldxsteps[1000+y]+abs(x-lastx));
            }
        }

        for (int j = 0; j < 2001; j++) {
            oldxsteps[j] = xsteps[j];
            oldysteps[j] = ysteps[j];
        }
        lastx = x;
        lasty = y;
    }
   
    int best = INF;
    for (int j = 0; j < 2001; j++) {
        best = min(best, min(xsteps[j], ysteps[j]));
    }

    cout << best << endl;
    return 0;
}
