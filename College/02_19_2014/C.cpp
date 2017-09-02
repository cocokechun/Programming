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
#include <climits>

#define MAX 10005
int n;

int graph[MAX][MAX]; 
using namespace std;
typedef long long ll;

int minDistance(int dist[], bool sptSet[]) {
    int best = INT_MAX, min_index;

    for (int v = 1; v <= n; v++) {
        if (sptSet[v] == false && dist[v] <= best) {
            best = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dis(int dist[], int src) {
    bool sptSet[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n; count++) {
        int u = minDistance(dist, sptSet);
        
        sptSet[u] = true;
        
        for (int v = 1; v <= n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u]+graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
         
}
