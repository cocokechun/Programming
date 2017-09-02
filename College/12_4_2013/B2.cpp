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
#define PI acos(-1)

typedef pair<double, double> point;


double dis(point a, point b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second)); 
}

int main() {
    int n;
    int tn;
    cin >> tn;
    point first = make_pair(0, 0);
    point pre = first;
    point cur = first; 
    double x, y;
    double radius;
    while (tn--) {
        cin >> radius >> n;
        double len = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            cur = make_pair(x, y);
            if (i == 0) {
                first = make_pair(x, y);
            } else {
                len += dis(pre, cur);
            }
            if (i == n-1) {
                len += dis(cur, first);
            }
            pre = cur;
        }
    
        double scale = 1 - (2 * PI * radius) / len;    
        if (scale > 0 && scale < 1) {
            printf("%lf\n", scale);
        } else {
            printf("Not possible\n");
        }
    }
    return 0;
}
