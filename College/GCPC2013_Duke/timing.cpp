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
typedef pair<int, double> state;

map<int, vector<state> > links;
map<int, set<int> > graph;

void run(double planes[], int n) {
    double old[n];

    for (int i = 0; i < n; i++) {
        old[i] = planes[i];
    }

    for (map<int, vector<state> >::iterator it = links.begin(); it != links.end(); it++) {
        int source = it -> first;
        vector<state> targets = it -> second;
        for (vector<state>::iterator itt = targets.begin(); 
                            itt != targets.end(); itt++) {
            int target = (*itt).first;
            double per = (*itt).second;
            planes[source] -= old[source] * per;
            planes[target] += old[source] * per;
            if (target == 0) {
                printf("plane[%d] to plane[0] add %f", source, old[source]);
                printf("planes[0] is %f\n", planes[0]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << planes[i] << ' ';
    }
    cout << endl;
}

double add_sum(int visited[], int first, double planes[], int n) {
    queue<int> q;
    q.push(first);
    visited[first] = 1;
    double sum = planes[first];

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        set<int> neighs = graph[cur];
        set<int>::iterator it;
        for (it = neighs.begin(); it != neighs.end(); it++)  {
            int next = *it;
            if (visited[next] == 0) {
                q.push(next);
                sum += planes[next];
                visited[next] = 1;
            }
        }
    }
    return sum;
}

void solve() {
    int n, m, t;
    cin >> n >> m >> t;

    double planes[n];
    for (int i = 0; i < n; i++) {
        cin >> planes[i]; 
    }

    for (int i = 0; i < m; i++) {
        int source, target;
        double per;
        cin >> source >> target >> per;
        links[source].push_back(make_pair(target, per));
        graph[source].insert(target);
    }

    for (int i = 0; i < t; i++) {
        run(planes, n);
    }

    int visited[n];
    memset(visited, 0, n * sizeof(int));
    double count = 0;
    double min = 1000000.00;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            double tmp = add_sum(visited, i, planes, n);
            if (tmp < min) {
                min = tmp;
            }
        }
    }
    printf("%0.9f\n", min);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        solve();
    }
}

