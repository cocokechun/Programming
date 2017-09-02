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
typedef pair<int, int> pii;
#define MAX 2500
#define INF 250000
int rows, cols, V;
int grid[45][45];
vector<pii> graph[MAX];
bool mst[MAX];
int key[MAX];

int is_valid(int r, int c) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

pii minKey() {
    int mini = INF;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (mst[v] == false && key[v] < mini) {
            mini = key[v];
            min_index = v;
        }
    }
    return make_pair(min_index, mini);
}

int main() {
    cin >> cols >> rows;
    V = cols * rows;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    // build the directed graph
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int cur = i * cols + j;
            //cout << i << ' ' << j << endl;
            int w = grid[i][j];
            if (is_valid(i-1, j)) {
                int up = (i-1) * cols + j;
                int x = grid[i-1][j];
                graph[cur].push_back(make_pair(up,min(w, x)));
            }
            if (is_valid(i+1, j)) {
                int down = (i+1) * cols + j;
                int x = grid[i+1][j];
                graph[cur].push_back(make_pair(down,min(w,x)));
            }
            if (is_valid(i, j-1)) {
                int left = i * cols + j - 1;
                int x = grid[i][j-1];
                graph[cur].push_back(make_pair(left,min(w,x)));
            }
            if (is_valid(i, j+1)) {
                int right = i * cols + j + 1;
                int x = grid[i][j+1];
                graph[cur].push_back(make_pair(right,min(w,x)));
            }
        }
    }

    // Prim's algrotihm
    for (int i = 0; i < V; i++) {
        key[i] = INF;
    }

    key[0] = 0;
    int sum = 0;

    for (int i = 0; i < V; i++) {
        pii mins = minKey();
        int u = mins.first;
        sum += mins.second; 
        //cout << u << ' ' << mins.second << endl;
        mst[u] = true;

        vector<pii> nghrs = graph[u];
        for (int j = 0; j < nghrs.size(); j++) {
            int v = nghrs[j].first;
            int w = nghrs[j].second; 

            if (mst[v] == false && w < key[v]) {
                key[v] = w;
            }
        }
    }
    cout << sum << endl;

    return 0;
}

