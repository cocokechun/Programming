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
#include <vector>

using namespace std;
typedef pair<int, int> pint;

void solve() {
    int n;
    cin >> n;
    pint pos[n+2];
    map<pint, vector<pint> > m;
    queue<pint> q;
    map<pint, int> visited;
   
    for (int i = 0; i < n+2; i++) {
        int a, b;
        cin >> a >> b;
        pos[i] = make_pair(a, b);
        visited[pos[i]] = 0;
    }

    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j < n+2; j++) {
            if (abs(pos[i].first - pos[j].first) +
                abs(pos[i].second - pos[j].second) <= 1000) {
                m[pos[i]].push_back(pos[j]);
            }
        }
    }

    q.push(pos[0]); 
    visited[pos[0]] = 1;
    while (!q.empty()) {
        //cout << "in queue size is " << q.size() << endl;
        pint cur = q.front();
        q.pop();

        if (cur == pos[n+1]) {
            cout << "happy" << endl;
            return;
        }

        vector<pint> neigh = m[cur];
        int size = neigh.size();
        /*for (std::vector<pint>::iterator it = neigh.begin(); it != neigh.end(); ++it) {
            pint cur_neigh = *it;
            if (visited[cur_neigh] == 0) {
                q.push(*it);
            }
        }*/
        for (int i = 0; i < size; i++) {
            pint cur_neigh = neigh[i];
            if (visited[cur_neigh] == 0) {
                q.push(cur_neigh);
                //cout << "pass " << cur_neigh.first << " " << cur_neigh.second <<endl;
                visited[cur_neigh] = 1;
            }
        }
    }
    cout << "sad" << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}

