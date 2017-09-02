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
#define MAX 10000
map<int, int> G[MAX];
struct edge {
    int vertex;
    int weight;
    edge (int v, int w): vertex(v), weight(w) {}
};

bool operator>(const edge &lhs, const edge& rhs) {
    return lhs.weight > rhs.weight;
}


void dijkstra(map<int, int> graph[], int n, int src, int dist[]) {
    priority_queue<edge, vector<edge>, greater<edge> > q;
    bool visited[n];
    memset(visited, 0, n);

    q.push(edge(src, 0));
    while (!q.empty()) {
        int v = q.top().vertex;
        int w = q.top().weight;
        if (!visited[v]) {
            dist[v] = w;
            for (map<int,int>::iterator it = graph[v].begin();
                 it != graph[v].end(); it++) {
                q.push(edge(it->first, it->second+dist[v]));
            }
            visited[v] = true;
        }
        q.pop();
    }
}

int shortestDist(map<int, int> graph[], int n, int src, int dest) {
    int dist[n];
    dijkstra(graph, n, src, dist);
    return dist[dest];
}

/* Assumed input:
 * n m
 * (all the weighted edges)
 */
int main2() {
    int n, m;
    cin >> n >> m;
   
    int from, to, dis;
    // directed graph here
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> dis;
        G[from][to] = dis;
        //G[to][from] = dis;
    }

    /*for (int i = 0; i < n; i++) {
        for (map<int,int>::iterator it = G[i].begin(); it != G[i].end(); it++) {
            printf("(%d, %d) ", it -> first, it -> second);
        }
        cout << endl;
    }*/

    int src = 0;
    int dist[n];
    dijkstra(G, n, src, dist);
    for (int i = 0; i < n; i++) {
        cout << i << ' ' << dist[i] << endl;
    }
}

/* Assumed input:
 * m (number of undirected edges)
 * edges(string, string, int)
 * src des
 */
int main() {
    int m;
    cin >> m;
    map<string, int> mm;
    int count = 0;

    string from, to;
    int dis;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> dis;
        if (mm.find(from) == mm.end()) {
            mm[from] = count;
            count ++;
        }
        if (mm.find(to) == mm.end()) {
            mm[to] = count;
            count ++;
        }
        int f = mm[from];
        int t = mm[to];
        G[f][t] = dis;
        G[t][f] = dis;
    }

    int n = count;
    int dist[n];
    string src, des;
    cin >> src >> des;
    dijkstra(G, n, mm[src], dist);
    cout << dist[mm[des]] << endl;
}
