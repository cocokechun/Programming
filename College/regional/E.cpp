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
#define N 205
#define INF 100000000 
int cost[N][N]; //cost matrix
int edges[N][N];
int n, max_match; // n workers and n jobs
int lx[N], ly[N]; // labels of X and Y parts
int xy[N]; // xy[x] - vertex that is matched with x
int yx[N]; //yx[y] - vertex that is matched with y
bool S[N], T[N]; // sets S and T in algorithm
int slack[N]; //as in the algorithm description
int slackx[N]; 
int prev[N]; // array for memorizing alternating paths

void init_labels() {
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            lx[x] = max(lx[x], cost[x][y]);
        }
    }
}

void update_labels() {
    int x,y,delta = INF;
    for (y = 0; y < n; y++) {
        if (!T[y])
            delta = min(delta, slack[y]);
    }
    for (x = 0; x < n; x++)
        if (S[x]) lx[x] -= delta; // update X labels
    for (y = 0; y < n; y++) {
        if (T[y]) ly[y] += delta; // update Y labels
    }
    for (y = 0; y < n; y++) { //update slack array
        if (!T[y])
            slack[y] -= delta;
    }
}

void add_to_tree(int x, int prevx) {
    S[x] = true; // add x to S
    prev[x] = prevx; // we nee this when augumenting

    for (int y = 0; y < n; y++) 
        if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
            slack[y] = lx[x] + ly[y] - cost[x][y];
            slackx[y] = x;
        }
}

void augument() {
    if (max_match == n) return;
    int x, y, root;
    int q[N], wr = 0, rd = 0;

    memset(S, false, sizeof(S));
    memset(T, false, sizeof(T));
    memset(prev, -1, sizeof(prev));
    for (x = 0; x < n; x++) 
        if (xy[x] == -1) {
            q[wr++] = root = x;
            prev[x] = -2;
            S[x] = true;
            break;
        }

    for (y = 0; y < n; y++) {
        slack[y] = lx[root] + ly[y] - cost[root][y];
        slackx[y] = root;
    }

    while (true) {
        while (rd < wr) {
            x = q[rd++];
            for (y = 0; y < n; y++) 
                if (cost[x][y] == lx[x] + ly[y] && !T[y]) {
                    if (yx[y] == -1) break;

                    T[y] = true;
                    q[wr++] = yx[y];

                    add_to_tree(yx[y], x);
                }
            if (y < n) break;
        }
        if (y < n) break;

        update_labels();
        wr = rd = 0;
        for (y = 0; y < n; y++) 
            if (!T[y] && slack[y] == 0) {
                if (yx[y] == -1) {
                    x = slackx[y];
                    break;
                } else {
                    T[y] = true;
                    if (!S[yx[y]]) {
                        q[wr++] = yx[y];
                        add_to_tree(yx[y], slackx[y]);
                    }
                }
            }
        if (y < n) break;
    }

    if (y < n) {
        max_match++;
        for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty) {
            ty = xy[cx];
            yx[cy] = cx;
            xy[cx] = cy;
        }
        augument();
    }
}

int hungarian() {
    int ret = 0;
    max_match = 0;
    memset(xy, -1, sizeof(xy));
    memset(yx, -1, sizeof(yx));
    init_labels();
    augument();
    for (int x = 0; x < n; x++) {
        ret += cost[x][xy[x]];
    }
    return ret;
}

int solve() {
    memset(cost, 0, N*N*sizeof(int));
    cin >> n;
    int max_edge = 0;

    // read edge weight
    // build a bipartite graph: one side is all vertices, the other side
    // is copy of all other vertices
    int w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1-i; j++) {
            cin >> w;
            edges[i][i+1+j] = w;
            edges[i+1+j][i] = w;
            max_edge = max(max_edge, w);
        }
    }

    // since hungarian solves maximum weighted matching, we will use flip costs
    // by doing maxcost - cost 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) { // we do not want (i,i) connected
                cost[i][j] = max_edge-edges[i][j];
            } else {
                cost[i][j] = -100;
            }
        }
    }

    hungarian(); // find max

    //get right cost again
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cost[i][j] = max_edge - cost[i][j];
            }
        }
    }

    int finalCost = 0;
    for (int x = 0; x < n; x++) {
        finalCost += cost[x][xy[x]];
    }

    return finalCost;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        cout << "Case " << i << ": " << solve() << endl;
    }
    return 0;
}
