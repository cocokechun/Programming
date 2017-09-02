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
#define MAX 1005
int weights[26];
int graph[MAX][MAX];
int dist[MAX];

int solve() {
    int K, W, H;
    cin >> K >> W >> H;

    memset(weights, 0, 26 * sizeof(int));
    memset(graph, 0, MAX * MAX * sizeof(int));

    char c;
    int w;
    for (int i = 0; i < K; i++) {
        cin >> c >> w;
        weights[c-'A'] = w;
    }

    int row_start, col_start;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c;
            if (c == 'E') {
                row_start = i;
                col_start = j;
            } else {
                graph[i][j] = weights[c-'A'];
            }
        }
    }
   
     
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        solve();
    }
}

