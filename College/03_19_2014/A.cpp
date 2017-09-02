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
typedef pair<int,int> pii;

#define MAX 15
pii loc[MAX];
int perm[MAX];

char dir(int i, int j) {
    if (loc[i].first == loc[j].first) {
        if (loc[i].second > loc[j].second) {
            return 'N';
        } else {
            return 'S';
        }
    }

    if (loc[i].second == loc[j].second) {
        if (loc[i].first > loc[j].first) {
            return 'E';
        } else {
            return 'W';
        }
    }

    return 0;
}

bool changed(int n) {
    if (n <= 1) {
        return true;
    }

    for (int k = 2; k < n; k++) {
        int cur = perm[k];
        int p = perm[k-1];
        int pp = perm[k-2];
        //printf("from %d to %d is %c\n", cur, p, dir(cur, p));
        //printf("from %d to %d is %c\n", p, pp, dir(p, pp));
        if (dir(cur,p) == 0 || dir(p,pp) == 0) {
            return false;
        }
        if (dir(cur,p) == dir(p,pp)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    n++;
    loc[0].first = 0;
    loc[0].second = 0;
    perm[0] = 0;

    for (int i = 1; i < n; i++) {
        cin >> loc[i].first >> loc[i].second;
        perm[i] = i;
    }
    perm[n] = n;
    loc[n].first = 0;
    loc[n].second = 0;
    n++;

    int total = 0;
    do {
        if (changed(n)) {
            total ++;
            //cout << "this okay" << endl;
        }
        /*for (int i = 0; i < n; i++) {
            cout << perm[i] << ' ';
        }
        cout << endl;*/
    } while (next_permutation(perm+1, perm+n-1));

    cout << total << endl;
}
