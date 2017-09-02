#include <iostream>
#include <math.h>

#define point pair <double, double>
using namespace std;


double dis(point A, point B) {
    return sqrt(pow(A.first-B.first,2) + pow(A.second - B.second, 2));
}

double sum_array(int end, double a[]) {
    int i;
    double res = 0.0;
    for (i = 0; i < end; i++) {
        res += a[i];
    }
    return res;
}

int solve() {
    int n;
    double a, b, c;
    cin >> n;
    if (n == 0) return 0;

    point start = make_pair(0,0);
    point end = make_pair(100,100);

    double pen[n];
    point p[n+1];
    double l[n+1];
    
    int i, j; 
    for (i = 0; i < n; i++) {
        cin>>a>>b>>c;
        p[i] = make_pair(a,b);
        pen[i] = c;
    }

    p[n] = end;
    l[0] = dis(start, p[0]) + 1.0;

    for (i = 1; i <= n; i++) {
        double total_p = sum_array(i, pen);
        double min_so_far = total_p + 1 + dis(start, p[i]);
        for (j = 0; j < i; j++) {
            total_p -= pen[j];
            double tmp = l[j] + total_p + dis(p[j], p[i]) + 1.0;
            if (tmp < min_so_far) {
                min_so_far = tmp;
            }
        l[i] = min_so_far;
        }
    }

    printf("%0.3f\n", l[n]);
    return 1;
}

int main() {
    while (solve());
    return 0;
}
