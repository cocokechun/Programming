#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstdio>

using namespace std;

#define MAX_V 810
typedef long long ll;
const ll inf = 1e13;
const ll inf2 = 1e10;

//ll rGraph[MAX_V][MAX_V];
vector<int> adj_list[MAX_V];
ll rGraph[MAX_V][MAX_V];
int parent[MAX_V]; // filled by BFS and to store path
bool visited[MAX_V];

void print_rGraph(int n, int m) {
    for (int i = 0; i < n+m+2; i++) {
        for (int j = 0; j < n+m+2; j++) {
            cout << rGraph[i][j] << ' ';
        }
        cout << endl;
    }
}

int bfs(int s, int t) {
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        int size = adj_list[u].size();
        for (int i = 0; i < size; i++) {
            int v = adj_list[u][i];
            if (visited[v] == false && rGraph[u][v] > 0 &&
                v != s) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
        /*for (int v=0; v<8; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }*/
    }

    //If we reach sink in BFS starting from source, then return true
    return (visited[t] == true);
}

void minCut(int s, int t, int n, int m, ll total_iq) {
    int u, v;
    ll max_flow = 0;

    // Augment the flow while there is path from source to sink
    while (bfs(s, t)) {
        // Find minimum residual capacity of the edges along the path filled
        // by BFS. Or we say find the maximum flow through the path found
        ll path_flow = inf;
        for (v = t; v != s; v = parent[v]) {
            printf("v is %d\n", v);
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]); 
        }

        printf("paht flow is %lld\n", path_flow);

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    print_rGraph(n, m);

    cout << (total_iq - max_flow) << endl;
    int counter1 = 0;
    for (int i = 1; i < n+1; i++) {
        if (rGraph[s][i]) {
            counter1 ++;
        }
    }

    cout << counter1 << endl;
    for (int i = 1; i < n+1; i++) {
        if (rGraph[s][i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    int counter2 = 0;
    for (int i = 1+n; i < 1+n+m; i++) {
        if (rGraph[t][i]) {
            counter2 ++;
        }
    }

    cout << counter2 << endl;
    for (int i = n+1; i < n+1+m; i++) {
        if (rGraph[t][i]) {
            printf("%d ", i-n);
        }
    }
    printf("\n");
}


int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int s = 0;
    int t = n + m + 1;
    memset(rGraph, 0, MAX_V * MAX_V);
    ll total_iq = 0;

    // Build a graph with extra source vertex, target vertex, and complement
    // graph of the middle part
    for (int i = 0; i < k; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        to += n;
        rGraph[from][to] = -1;
    }

    for (int i = 1; i < n+1; i++) {
        ll iq;
        scanf("%lld", &iq);
        rGraph[s][i] = iq;
        total_iq += iq;
        adj_list[s].push_back(i);
        adj_list[i].push_back(s);
    }

    for (int i = n+1; i < n+1+m; i++) {
        ll iq;
        scanf("%lld", &iq);
        rGraph[i][t] = iq;
        total_iq += iq;
        adj_list[i].push_back(t);
        adj_list[t].push_back(i);
    }

    // make cap inf if two vertices are not adjacent
    for (int i = 1; i < n+1; i++) {
        for (int j = n+1; j < n+1+m; j++) {
            if (rGraph[i][j] == -1) {
                rGraph[i][j] = 0;
            } else {
                rGraph[i][j] = inf2;
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }

    print_rGraph(n, m);

    minCut(0, n+m+1, n, m, total_iq);
}
