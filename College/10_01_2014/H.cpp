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
pii points[MAX];
bool see[MAX];


void solve(int n, int m) {
    memset(points, 0, sizeof(pii) * MAX);
    memset(see, 0, MAX);
    set<int> xs;
    set<int> ys;
    map<int, set<int> > xcords;
    map<int, set<int> > ycords;
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        xcords[points[i].first].insert(points[i].second);
        ycords[points[i].second].insert(points[i].first);
    }

    char line[100];
    for (int i = 0; i < m; i++) {
        cin >> line;
        if (line[0] == 'x') {
            xs.insert(atoi(line+2));
        } else {
            ys.insert(atoi(line+2));
        }
    }

    for (int i = 0; i < n; i++) {
        int x = points[i].first;
        int y = points[i].second;

        set<int>::iterator line = xs.upper_bound(x);
        if (line != xs.end()) {
            set<int>::iterator point = ycords[y].upper_bound(x);
            if (point == ycords[y].end() || *point > *line) {
                see[i] = true;
            }
        }

        line = ys.upper_bound(y);
        if (line != ys.end()) {
            set<int>::iterator point = xcords[x].upper_bound(y);
            if (point == xcords[x].end() || *point > *line) {
                see[i] = true;
            }
        }

        line = xs.lower_bound(x);
        if (line != xs.begin()) {
            line --;
            set<int>::iterator point = ycords[y].lower_bound(x);
            if (point != ycords[y].begin()) {
                point--;
                if (*point < *line) {
                    see[i] = true;
                }
            } else {
                see[i] = true;
            }
        }

        line = ys.lower_bound(y);
        if (line != ys.begin()) {
            line --;
            set<int>::iterator point = xcords[x].lower_bound(y);
            if (point != xcords[x].begin()) {
                point--;
                if (*point < *line) {
                    see[i] = true;
                }
            } else {
                see[i] = true;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        if (see[i]) count ++;
    }
    cout << count << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    while (! (n == 0 && m == 0)) {
        solve(n, m);
        cin >> n >> m;
    }
}
