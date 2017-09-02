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

#define PI 3.14159265
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX (1<<15)

int dp[MAX][20];
pii positions[20];
pii speeds[20];
int numPoints[MAX];

double toDegree(int d) {
    return d * PI / 180;
}

double solve(int n, int m) {
    memset(dp, 0, MAX*20*sizeof(int));
    memset(numPoints, 0, MAX*sizeof(int));

    int x, y, d, s;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> s;
        positions[i] = make_pair(x,y);
        speeds[i] = make_pair(d,s);
    }

    for (int i = 0; i < MAX; i++) {
        numPoints[i] = countPoints(i);
    }

    for (int i = 1; i <= n; i++) { // how many points to catch
        if (i == 1) {
            for (int j = 0; j < n; j++) {
                double a = findDis(make_pair(0,0), )
            }
            continue;
        }

        for (int j = 0; j < n; j++) {
            for 
        }

        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0) break;
        printf("%0.2f\n", solve(n,m));
    }
    return 0;
}
