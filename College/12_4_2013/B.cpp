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
#define MIN 1000000
#define MAX 10000000
#define ERR 0.0001

typedef pair<double, double> point;


double dis(point a, point b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second)); 
}

double scale(double len, double num, double r, int n) {
    double new_len = len * num;
    double angle = (180 * n - 180 * (n-2)) * PI / 180;
    new_len += (angle * r);
    return new_len;
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
        
        printf("len is %lf\n", len);
        double best = 100;
        double best_scale = 0;
        for (double i = MIN; i < MAX; i++) {
            double res = scale(len, i/MAX, radius, n);
            /*if (i/MAX == 0.730494) {
                printf("i/MAX is %lf res is %lf\n", i/MAX, res);
            }*/
            if (abs(len - res) < best) {
                best = abs(len - res);
                best_scale = i/MAX;
                //printf("best is %lf, best_scale is %lf\n", best, i/MAX);
            }
        }

        if (best <= ERR) {
            printf("%lf\n", best_scale);
        } else {
            printf("Not possible\n");
        }
    }
    return 0;
}
