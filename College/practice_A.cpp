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
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int p = 0;
    int array[n];
    memset(array, 0, n * 4);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m;) {
            if (array[j] == 0) {
                j++;
            }
            p = (p+1) % n;
            //cout << p << endl;
        }
        array[p] = 1;
        if (i != k-1) {
            p = (p+1) % n;
        }

        for (int j = 0; j < n; j++) {
            cout << array[j] << ' ';
        }
        cout << endl;
    }

    cout << p + 1 << endl;
}

