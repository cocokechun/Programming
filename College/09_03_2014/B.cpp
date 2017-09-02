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

int ways[50][5];

int tile(int n) {
    int m = 3 * n / 2;
    memset(ways, 0, 50 * 5);

    ways[1][0] = 1;
    ways[1][1] = 1;
    ways[2][2] = 1;
    ways[2][3] = 1;
    ways[3][4] = 3;

    for (int i = 4; i <= m; i++) {
        ways[i][0] = ways[i-1][4] + ways[i-2][3];
        ways[i][1] = ways[i-1][4] + ways[i-2][2];
        ways[i][2] = ways[i-1][1];
        ways[i][3] = ways[i-1][0];
        ways[i][4] = ways[i-1][3] + ways[i-2][1] + ways[i-3][4];
    }

    return ways[m][4];
}

int main() {
    int n;

    while (1) {
        cin >> n;
        if (n == -1) return 0;

        if (n == 0) { 
            cout << 1 << endl;
        } else {
            cout << tile(n) << endl;
        }
    }
    return 0;
}
