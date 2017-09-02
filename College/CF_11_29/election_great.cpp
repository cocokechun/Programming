/* BEGINS CODE TEMPLATE */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <complex>
#include <algorithm>
//#define ONLINE_JUDGE
using namespace std;

const int MAX = 100005;
/* ENDS CODE TEMPLATE */

vector< pair<int, int> > G[100003];
bool needed[100003];

int dfs(int s, int p)
{
    int total = 0;
    int n = G[s].size();
    for (int i = 0; i < n; i++) {
        int v = G[s][i].first;
        int w = G[s][i].second;
        if (v == p) continue;
        int ret = dfs(v, s);
        if (w == 2) {
            if (ret == 0) {
                needed[v] = true;
                total++;
            } else {
                total += ret + 1;
            }
        } else {
            total += ret;
        }
    }

    return total;
}

int main(int argc, char **argv)
{
    int i, n, x, y, t;
    scanf("%d", &n);

    for (i = 1; i < n; i++) {
        scanf("%d %d %d", &x, &y, &t);
        G[x].push_back(make_pair(y, t));
        G[y].push_back(make_pair(x, t));
    }

    dfs(1, 0);
    int ans = 0;
    for (i = 2; i <= n; i++)
        if (needed[i])
            ans++;
    printf("%d\n", ans);
    for (i = 2; i <= n; i++)
        if (needed[i])
            printf("%d ", i);
    return EXIT_SUCCESS;
}
