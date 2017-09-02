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

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (5 - num >= m) {
            count ++;
        }
    }

    cout << count / 3 << endl;
}

