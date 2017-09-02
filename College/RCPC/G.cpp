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

pair<bool, int> run(map<int, vector<int> > graph, int n, int set_num) {
    int count = 1;
    int counter = 0;

    //printf("set_num is %d\n", set_num);
    int m[n+5];
    memset(m, 0, n+5);
    while (set_num > 0) {
        if (set_num % 2 == 1) {
            vector<int> nexts = graph[count];
            m[count] = 1;
            for (vector<int>::iterator it = nexts.begin(); it != nexts.end();
                    it++) {
                m[*it] = 1; 
            }
            counter ++;
        }
        set_num /= 2;
        count ++;
    }

    bool ind = true;
    for (int i = 1; i < n+1; i++) {
        if (m[i] == 0) {
            ind = false;
        }
    }
    //printf("counter is %d\n", counter);
    //printf("n is %d\n", n);
    //printf("size of set is %zu\n", s.size());
    return make_pair(ind, counter);
}

void solve() {
    int n;
    scanf("%d", &n);

    map<int, vector<int> > graph;

    for (int i = 1; i < n+1; i++) {
        int deg;
        scanf("%d", &deg);
        for (int j = 0; j < deg; j++) {
            int next;
            scanf("%d", &next);
            graph[i].push_back(next);
        }

        // print
        /*
        for (int j = 0; j < deg; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
        */
    }

    int trial = 1 << n;
    int min_count = 21;
    for (int i = 1; i < trial; i++) {
        pair<bool, int> res = run(graph, n, i);
        if (res.first) {
            if (res.second < min_count) {
                min_count = res.second;
            }
        }
    }
    cout << min_count << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
}

