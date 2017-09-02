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

void solve(int n) {
    int sum = 0;
    vector<int> divs;

    for (int i = 1; i * i <= n; i++) {
        if (i * (n/i) == n) {
            if (i != n) {
                sum += i;
                divs.push_back(i);
            }
            if ((n/i != n) && (n/i != i)) {
                sum += (n/i);
                divs.push_back(n/i);
            }
        }
    }

    if (sum != n) {
        cout << n << " is NOT perfect." << endl;
    } else {
        sort(divs.begin(), divs.end());
        cout << n << " = ";
        for (int i = 0; i < divs.size(); i++) {
            if (i < divs.size()-1) {
                cout << divs[i] << " + ";
            } else {
                cout << divs[i] << endl;
            }
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        if (n == -1) break;
        solve(n);
    }
}

