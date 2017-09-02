#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

typedef vector<double> polynomial;
const double PI = 3.14159265;

double eval (polynomial p, double x)
{
    double curx = 1;
    double ans = 0;
    for (int i = 0; i < p.size(); i++) {
        ans += curx * p[i];
        curx *= x;
    }
    return ans;
}

double vol (polynomial p, double a, double b)
{
    return eval(p,b) - eval(p,a);
}

int main() {
    int n;
    int tn = 0;
    double xlow, xhigh, inc;
    polynomial p;

    while (scanf("%d", &n) > 0) {
        tn++;
        p.assign(n+1, 0);
        for (int i = 0; i < n+1; i++) {
            scanf("%lf", &p[i]);
        }
        scanf("%lf %lf %lf", &xlow, &xhigh, &inc);
        
        polynomial sqp;
        sqp.assign(2*n+1, 0);
        
        for (int i = 0; i < 2*n+1; i++) {
            for (int j = 0; j <= i; j++) {
                if (j >= p.size() || i-j >= p.size()) continue;
                sqp[i] += p[j]*p[i-j];
            }
        }
        polynomial botp;
        botp.assign(2*n+2, 0);

        for (int i = 1; i < botp.size(); i++) {
            botp[i] = sqp[i-1]/i*PI;
        }

        vector<double> marks;
        marks.clear();

        for (int i = 1; i <= 8; i++) {
            if (vol(botp, xlow, xhigh) < i*inc) {
                break;
            }

            //Binary search for height marking
            double low = xlow;
            double high = xhigh;
            double val = i*inc;
            double mid;
            double mid_val;
            
            while (high-low >= 0.00001) {
                mid = (high+low)/2;
                mid_val = vol(botp, xlow, mid);
                if (mid_val <= val) {
                    low = mid;
                } else {
                    high = mid;
                }
            }

            marks.push_back((low+high)/2);
        }

        printf("Case %d: %0.2lf\n", tn, vol(botp, xlow, xhigh));
        if (marks.size() == 0) {
            printf("insufficient volume\n");
        } else {
            for (int i = 0; i < marks.size(); i++) {
                printf("%0.2lf ", marks[i]-xlow);
            }
            printf("\n");
        }
    }
}
