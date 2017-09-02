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

int main () {
    int N, T1, T2, T3;
    vector<int> ticks;
    cin >> N >> T1 >> T2 >> T3;
    while (!((N==0) && (T1==0) && (T2==0) && (T3==0))) {
        int max_ticks = 0;
        max_ticks += 4 * N - 1;
        
        if (T1 < T2) {
            max_ticks += T2 - T1;
        } else {
            max_ticks += (N - T1) + T2;
        }

        if (T3 <  T2) {
            max_ticks += T2 - T3;
        } else {
            max_ticks += T2 + (N-T3);
        }

        ticks.push_back(max_ticks);
        cin >> N >> T1 >> T2 >> T3;
    }

    for (int i = 0; i < ticks.size(); i++) {
        cout << ticks[i] << endl;
    }

    return 0;
}
