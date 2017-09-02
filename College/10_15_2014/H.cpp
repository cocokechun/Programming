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
#define N 55
#define INF 100000000 
int cost[N][N]; //cost matrix
int ftime[N][N];
int utime[N][N];
int n, max_match; // n workers and n jobs
int lx[N], ly[N]; // labels of X and Y parts
int xy[N]; // xy[x] - vertex that is matched with x
int yx[N]; //yx[y] - vertex that is matched with y
int bestxy_frame[N]; //record the best matching of framing
int bestyx_frame[N]; //record the best matching of framing
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

void solve() {
    memset(cost, 0, N*N*sizeof(int));
    int max_ftime = 0;

    // read framing time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ftime[i][j];
            max_ftime = max(max_ftime, ftime[i][j]);
        }
    }

    // since hungarian solves maximum weighted matching, we will use flip costs
    // by doing maxcost - cost 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = max_ftime-ftime[i][j];
        }
    }

    hungarian(); // find max
    for (int x = 0; x < n; x++) {
        bestxy_frame[x] = xy[x];
    }

    for (int y = 0; y < n; y++) {
        bestyx_frame[y] = yx[y];
    }

    // read upholstering time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> utime[i][j];
        }
    }

    memset(cost, 0, N*N*sizeof(int));
    int max_total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = utime[i][j] + 
                         max(ftime[i][bestxy_frame[i]], ftime[bestyx_frame[j]][j]);
            max_total = max(max_total, cost[i][j]);
        }
    }
   
     
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = max_total - cost[i][j];
        }
    }

    hungarian(); 
    
    //get right cost again
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = max_total - cost[i][j];
        }
    }

    for (int x = 0; x < n; x++) {
        cout << "Worker " << (x+1) << ": " << (bestxy_frame[x]+1) << ' ' << (xy[x]+1)<< ' ' << (cost[x][xy[x]]) << endl;
    }

    int idle = 0;
    for (int x = 0; x < n; x++) {
        idle += (cost[x][xy[x]] - ftime[x][bestxy_frame[x]] - utime[x][xy[x]]);
    }
    cout << "Total idle time: " << idle << endl;
}

int main() {
    int index = 1;
    while (cin >> n) {
        if (n == 0) break;
        cout << "Case " << index << ":" << endl;
        solve();
        index++;
    }
    return 0;
}
