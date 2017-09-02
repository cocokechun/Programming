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
typedef pair<int, int> pii;
#define MAX 100005
pii colors[MAX];
map<int, int> home;
int freq[MAX];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> colors[i].first >> colors[i].second;
        if (home.find(colors[i].first) == home.end()) {
            home[colors[i].first] = 1;
        } else {
            home[colors[i].first] ++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (home.find(colors[i].second) != home.end()) {
            freq[i] += home[colors[i].second];
        }
    }

    for (int i = 0; i < n; i++) {
        int num1 = freq[i] + n - 1;
        cout << num1 << ' ' << 2 * (n-1) - num1 << endl;
    }
}
