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

using namespace std;

int main() {
    int tn;

    for (cin >> tn; tn > 0; tn--) {

        int n;
        cin >> n;
        vector<int> adj(n, 0);
        for (int i = 0; i < n; i++) {
            adj[i] |= (1 << i);
            int vs;
            cin >> vs;
            int v;
            for (int j = 0; j < vs; j++) {
                cin >> v;
                adj[i] |= (1 << (v-1));
            }
        }

        int best = 21;
        for (int i = 0; i < (1 << n); i++) {
            int cover = 0;
            int counter = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    cover |= adj[j];
                    counter ++;
                }
            }
            if (cover == (1<<n)-1 && counter < best) {
                best = counter;
            }
        }
        cout << best << endl; 

    }
}
