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
#include <limits.h>
#include <deque>

#define MAX 300000
using namespace std;
typedef pair<int,int> pii;
vector<pii> graph[MAX];
bool visited[MAX];
int dist[MAX];

int main() {
    int n, m;
    cin >> n >> m;

    if (abs(n-m) % 2 != 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int V = (n+1) * (m+1);
    int cols = m+1;
    char c;

    // build the graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            int left_up = i*cols+j;
            int right_down = (i+1)*cols+j+1;
            int right_up = i*cols+j+1;
            int left_down = (i+1)*cols+j;
            if (c == '\\') {
                graph[left_up].push_back(make_pair(right_down, 0));
                graph[right_down].push_back(make_pair(left_up, 0));
                graph[right_up].push_back(make_pair(left_down, 1));
                graph[left_down].push_back(make_pair(right_up, 1));
            } else {
                graph[left_up].push_back(make_pair(right_down, 1));
                graph[right_down].push_back(make_pair(left_up, 1));
                graph[right_up].push_back(make_pair(left_down, 0));
                graph[left_down].push_back(make_pair(right_up, 0));
            }
        }
    }

    // use deque to do breadth first search
    deque<int> dq;
    dq.push_front(0);
    visited[0] = true;
    while (!dq.empty() && !visited[V-1]) {
        int cur = dq.front();
        vector<pii> nghrs = graph[cur];
        dq.pop_front();

        for (int i = 0; i < nghrs.size(); i++) {
            int v = nghrs[i].first;
            int w = nghrs[i].second;
            if (!visited[v]) {
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
                visited[v] = true;
                dist[v] = dist[cur] + w;
            }
        }
    }

    cout << dist[V-1] << endl;
    return 0;
}
