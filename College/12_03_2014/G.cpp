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
#include <climits>

using namespace std;
typedef long long ll;

#define MAX 1000005
bool seen[MAX];
vector<int> sizes;
vector<int> intervals;
vector<int> bricks[500005];
vector<ll> buckets[500005];

int main() {
    int n;
    cin >> n;

    int m, tmp;
    for (int i = 0; i < n; i++) {
        cin >> m;
        seen[m] = true;
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            bricks[i].push_back(tmp);
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (seen[i]) {
            sizes.push_back(i);
        }
    }

    sort(sizes.begin(), sizes.end());

    intervals.push_back(sizes[0]);

    for (int i = 1; i < sizes.size(); i++) {
        intervals.push_back(sizes[i]-sizes[i-1]);
    }

    for (int i = 0; i < n; i++) {
        int acc = 0;
        for (int j = 0; acc < bricks[i].size(); j++) {
            ll sum = 0;
            for (int k = 0; k < intervals[j]; k++) {
                sum += bricks[i][k+acc];
            }
            buckets[j].push_back(sum);
            acc += intervals[j];  
        }
    }

    ll res = LLONG_MIN;
    ll acc = 0;
    for (int i = 0; i < intervals.size(); i++) {
        ll best = LLONG_MIN;
        for (int j = 0; j < buckets[i].size(); j++) {
            best = max(best, buckets[i][j]);
        }
        acc += best;
        res = max(res, acc);
    }
    cout << res << endl;
    return 0;
}
