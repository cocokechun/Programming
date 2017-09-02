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
#define MOD 1000000007
#define MAX 100005
map<int, int> graph[MAX];

void add_edge(int u, int v) {
}

bool has_cycle(int v, int visited[]) {
    bool res = false;
    visited[v] = false;

    for (map<int, int>::iterator it = graph[v].begin(); 
        it != graph[v].end(); it++) {
        int u = it -> first;
        int freq = it -> second;
        if (freq == 2 || (u != v && visited[u])) {
            return true;
        }
        if (u != v && visited[u] == false) {
            //visited[u] = true;
            res |= has_cycle(u, visited);
        }
    }
    return res;
}

int count(int v, int p) {
    int res = 1;

    for (map<int, int>::iterator it = graph[v].begin(); 
        it != graph[v].end(); it++) {
        int u = it -> first;
        if (u != p) {
            res += count(u, v);
        }
    } 
    return res % MOD;
}

int main() {
    
}

