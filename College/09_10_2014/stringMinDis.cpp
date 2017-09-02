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

int solve(string a, string b) {
    int n = a.size();
    int m = b.size();

    int dis[n+1][m+1];
    memset(dis, 0, n * m * 4);

    dis[0][0] = 0;
    for (int i = 0 ; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i == 0) {
                dis[i][j] = j; 
                continue;
            }
            if (j == 0) {
                dis[i][j] = i; 
                continue;
            }
            dis[i][j] = max(n,m);
            if (a[i-1] == b[j-1]) {
                dis[i][j] = min(dis[i][j], dis[i-1][j-1]);
            }
            dis[i][j] = min(dis[i][j], min(dis[i-1][j-1]+1,
                            min(dis[i-1][j]+1, dis[i][j-1]+1)));
        }
    }

    /*for (int i = 0 ; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout <<  i << ' ' << j << ' ' << dis[i][j] << ' ';
        }
        cout << endl;
    }*/

    return dis[n][m];
}

int main() {
    string a, b;

    cout << solve("mart", "karma") << endl;
    return 0;
}
