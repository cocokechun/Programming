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

typedef struct Edge {
    int to;
    int from;
    int w;
    Edge(int a, int b, int c): to(a), from(b), w(c)
    {
    }
} Edge;

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
    deque<Edge> dq;
    dq.push_front(Edge(0, 0, 0));
    while (!dq.empty()) {
        int cur = dq.front().to;
        int from = dq.front().from;
        int cur_w = dq.front().w;
        dq.pop_front();
        if (visited[cur]) continue;

        dist[cur] = dist[from] + cur_w;
        visited[cur] = true;
        if (cur == V-1) {
            cout << dist[V-1] << endl;
            return 0;
        }

        vector<pii> nghrs = graph[cur];
        for (int i = 0; i < nghrs.size(); i++) {
            int v = nghrs[i].first;
            int w = nghrs[i].second;
            if (w == 0) {
                dq.push_front(Edge(v, cur, w));
            } else {
                dq.push_back(Edge(v, cur, w));
            }
        }
    }

    return 0;
}
