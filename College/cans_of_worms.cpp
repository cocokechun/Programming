#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <pair>

using namespace std;

int solve_one(set<int> pos, map<int, int> pos_rad, int p) {
    set<int> local_pos;
    copy(pos.begin(), pos.end(), inserter(local_pos, local_pos.begin()));

    queue<pair<int, int>> q;
    q.push(make_pair(p-pos_rad[p], p+pos_rad[p]));
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        set<int>::iterator itlow, itup, it;
        itlow = local_pos.lower_bound(poscur - pos_rad[cur]);
        ithigh = local_pos.upper_bound(cur + pos_rad[cur]);
        
        for (it = itlow; it != ithigh; it++) {
            int victim = *it;
            q.push(make_pair(victim-pos_rad[victim], victim+pos_rad[victim]));
        }
    }

}

int solve() {
    int n;
    cin >> n;
    if (n == 0) return -1;

    set<int> pos;
    map<int, int> pos_rad;
    int pos_array[n];
    for (int i=0; i<n; i++) {
        int p, r;
        cin >> p >> r; 
        pos.insert(p);
        pos_rad[p] = r;
        pos_array[i] = p;
    }

    for (int i=0; i<n; i++) {
        int res = solve_one(pos, pos_rad, pos_array[i]);
        cout << res << ' ';
    }
    cout << endl;
    return 0;
}

int main() {
    while (1) {
        if (solve() == -1) {
            break;
        }
    }
}

