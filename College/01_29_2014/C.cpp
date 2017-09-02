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
#include <limits.h>

using namespace std;
typedef long long ll;

#define MAX 105
#define V 105
long long graph[MAX][MAX];
int n, m;

int minDistance(long long dist[], bool sptSet[])
{
   // Initialize min value
   int best = INT_MAX, min_index;
 
   for (int v = 1; v <= n; v++)
     if (sptSet[v] == false && dist[v] <= best)
         best = dist[v], min_index = v;
 
   return min_index;
}

long long di(int src)
{
     long long dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
 
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
 
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
 
     // Find shortest path for all vertices
     for (int count = 0; count < n-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
 
       // Mark the picked vertex as processed
       sptSet[u] = true;
 
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 1; v <= n; v++)
 
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
    return dist[n]; 
}

int main() {
    cin >> n >> m;

    int s, t;
    long long c;

    memset(graph, 0, sizeof(long long) * MAX * MAX);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &s, &t, &c);
        graph[s][t] = c;
        graph[t][s] = c;
        //cout << s << ' ' << t << ' ' << c << endl;
    }

    long long res = di(1);
    //cout << res << endl;
    long long high = res;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (graph[i][j] > 0) {
                graph[i][j] *= 2;
                graph[j][i] *= 2;
                long long tmp = di(1);
                //cout << i << ' ' << j << ',' << tmp << endl;
                if (tmp > high) {
                    high = tmp;
                }
                graph[i][j] /= 2;
                graph[j][i] /= 2;
            }
        }
    }

    cout << high-res << endl;
}
