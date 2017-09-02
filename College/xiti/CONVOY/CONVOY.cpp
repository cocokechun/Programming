#include <iostream>

using namespace std;

#define MAX 1005

typedef long long ll;

double t[MAX]; //t[i] is time taken for car i to cross the bridge
ll w[MAX];   //acc weight for cars
double ts[MAX]; // min time for i cars
double t_max[MAX][MAX]; //max time from i to j

int main() {
    ll W, n;
    double S;

    cin >> W >> S >> n;

    ll a;
    double v;
    for (int i = 1; i <= n; i++) {
        cin >> a >> v;
        t[i] = S/v * 60; 
        w[i] = w[i-1] + a;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == j) {
                t_max[i][j] = t[i];
            } else {
                t_max[i][j] = max(t_max[i][j-1], t[j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < i; k++) {
            if (w[i] - w[k] <= W) {
                double tmp = ts[k] + t_max[k+1][i];
                ts[i] = (ts[i] == 0) ? tmp: (min(ts[i], tmp));
            }
        }
    }

    printf("%.1f\n", ts[n]);
}
