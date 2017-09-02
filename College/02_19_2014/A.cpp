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

#define MAX 10005
vector<int> knots;
bool rope[MAX];

int main() {
    int n, m;
    cin >> n >> m;

    int num;
    for (int i = 0; i <= m; i++) {
        rope[i] = false;
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        knots.push_back(num);
        rope[num] = true;
    }

    sort(knots.begin(), knots.end());

    int counter = 0;
    for (int i = 1; i < m; i++) {
        bool can_fold = true;
        for (int j = 0; j < n; j++) {
            int k = knots[j];
            if (2*i-k >= 0 && 2*i-k <= m) {
                can_fold |= false;
            }
        }
        if (can_fold) {
            //cout << i << endl;
            counter++;
        }
    }
    cout << counter << endl;
}
