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
ll costs[MAX];
bool visited[MAX];
vector<int> graph[MAX];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b); 
        graph[b].push_back(a); 
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // do breadth first search to find the sum of costs
                           // of the component
            queue<int> q;
            q.push(i);
            ll sum = 0;
            visited[i] = true;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                sum += costs[cur];

                for (int j = 0; j < graph[cur].size(); j++) {
                    if (!visited[graph[cur][j]]) {
                        visited[graph[cur][j]] = true;
                        q.push(graph[cur][j]);
                    }
                }
            }

            if (sum != 0) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }

        }
    }

    cout << "POSSIBLE" << endl;
    return 0;
}
