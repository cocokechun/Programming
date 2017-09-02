#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX_DEG 11
#define slice 0.000005

double coef[MAX_DEG];
double marks[MAX_DEG];

double plug(double x) {
    double res = 0;
    res += coef[0];

    double prod = 1;
    for (int i = 1; i < MAX_DEG; i++) {
        if (coef[i] != 0) {
            res += (coef[i] * prod);
        }
        prod *= x;
    }
    return res;
}

int main() {
    int n;
    double low, high, volume;
    int tn = 0;
    while (scanf("%d", &n) > 0) {
        tn ++;
        memset(coef, 0, MAX_DEG * sizeof(double));
        memset(marks, 0, MAX_DEG * sizeof(double));
        for (int i = 0; i < n+1; i++) {
            scanf("%lf", &coef[i]);
        }
        scanf("%lf %lf %lf", &low, &high, &volume);
        double v = 0;
        int counter = 0;
        for (double x = low; x < high; x += slice) {
            double mid = (x + x + slice) / 2.0;
            //double mid_value = plug(mid);
            //double trip = (plug(x) + plug(x+slice)) / 2;
            //double radius = 2.0/3 * mid_value + 1.0/3 * trip;
            double radius = plug(mid);
            v += (radius * radius * acos(-1) * slice);
            if (counter < 8 && v > (counter+1) * volume) {
                marks[counter] = mid;
                counter++;
            }
        }

        /*for (int i = 0; i < MAX_DEG; i++) {
            printf("%lf ", coef[i]);
        }*/

        printf("Case %d: %0.2lf\n", tn, v);
        if (counter == 0) {
            printf("insufficient volume\n");
        } else {
            for (int i = 0; i < counter; i++) {
                printf("%0.2lf ", marks[i]-low);
            }
            printf("\n");
        }
    }
}
