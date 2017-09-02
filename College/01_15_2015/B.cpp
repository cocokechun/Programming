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

vector<pair<int, int> > points;

int main() {
    int n, k;
    cin >> n >> k;

    int cur = 0;
    int dis;
    char dir;
    for (int i = 0; i < n; i++) {
        cin >> dis >> dir;
        if (dir == 'R') {
            points.push_back(make_pair(cur, 1));
            cur += dis;
            points.push_back(make_pair(cur, -1));
        } else {
            points.push_back(make_pair(cur, -1));
            cur -= dis;
            points.push_back(make_pair(cur, 1));
        }
    }

    sort(points.begin(), points.end());
    int res = 0;
    int layer = 0;
    int pre_x = 0;

    for (int i = 0; i < points.size(); i++) {
        //cout << points[i].first << ' ' << points[i].second << endl;
        //cout << points[i].first << ' ' << points[i].second << ' ' << pre_x << ' ' << layer << endl;
        if (points[i].second == 1) {
            layer ++;
            if (layer == k) {
                pre_x = points[i].first;
            }
        } else {
            if (layer == k) {
                res += (points[i].first - pre_x);
            }
            layer--;
        }
    }

    cout << res << endl;
    return 0;
}
