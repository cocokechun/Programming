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
typedef pair<ll, ll> pll;
#define MAX 10005
#define BIG 1000000007
#define P 509
vector<int> A[MAX];
vector<int> B[MAX];
char Alabels[MAX];
char Blabels[MAX];
int Bsizes[MAX];

pll hashTrees(int cur, set<ll> &S) {
    if (A[cur].size() == 0) {
        ll h = ('('*P*P + Alabels[cur] * P + ')') % BIG;
        ll multiplier = P * P; 
        S.insert(h);
        return make_pair(h, multiplier);
    }

    vector<int> nghrs = A[cur];
    ll h = '(';
    ll multiplier = P;

    h = (h*P) % BIG;
    h = (h+Alabels[cur]) % BIG;
    multiplier = (multiplier * P) % BIG;

    for (int i = 0; i < nghrs.size(); i++) {
        pll sub = hashTrees(nghrs[i], S);
        h = (h * sub.second) % BIG;
        h = (h + sub.first) % BIG;
        multiplier = (multiplier * sub.second) % BIG;
    }
    h = (h*P) % BIG;
    h = (h + ')') %  BIG;
    S.insert(h);
    multiplier = (multiplier * P) % BIG;
   
    return make_pair(h, multiplier); 
}

pll findTrees(int cur, set<ll> &S, int &best) {
    if (B[cur].size() == 0) {
        ll h = ('('*P*P + Blabels[cur] * P + ')') % BIG;
        ll multiplier = P * P; 
        if (S.find(h) != S.end()) { //find it 
            best = max(best, Bsizes[cur]);
        }
        return make_pair(h, multiplier);
    }

    vector<int> nghrs = B[cur];
    ll h = '(';
    ll multiplier = P;

    h = (h*P) % BIG;
    h = (h+Blabels[cur]) % BIG;
    multiplier = (multiplier * P) % BIG;

    for (int i = 0; i < nghrs.size(); i++) {
        pll sub = findTrees(nghrs[i], S, best);
        h = (h * sub.second) % BIG;
        h = ( h + sub.first) % BIG;
        multiplier = (multiplier * sub.second) % BIG;
    }

    h = (h*P) % BIG;
    h = (h + ')') % BIG;
    if (S.find(h) != S.end()) {
        best = max(best, Bsizes[cur]);
    }
    multiplier = (multiplier * P) % BIG;

    return make_pair(h, multiplier);
}

int findSizes(vector<int> tree[], int sizes[], int cur) {
    if (tree[cur].size() == 0) {
        sizes[cur] = 1;
        return 1;
    }

    int count = 1;
    vector<int> nghrs = tree[cur];
    for (int i = 0; i < nghrs.size(); i++) {
        count += findSizes(tree, sizes, nghrs[i]);
    }
    sizes[cur] = count;
    return count;
}

int solve() {
    int n, m;
    cin >> n >> m;

    char type;
    int p;
    memset(Alabels, 0, MAX);
    memset(Blabels, 0, MAX);
    memset(Bsizes, 0, MAX*sizeof(int));

    for (int i = 0; i < n; i++) {
        A[i].clear();
    }

    for (int i = 0; i < m; i++) {
        B[i].clear();
    }

    for (int i = 0; i < n; i++) {
        cin >> type >> p;
        if (p != -1) A[p].push_back(i);
        Alabels[i] = type;
    }

    for (int i = 0; i < m; i++) {
        cin >> type >> p;
        if (p != -1) B[p].push_back(i);
        Blabels[i] = type;
    }

    findSizes(B, Bsizes, 0);

    int best = 0;
    set<ll> S;
    hashTrees(0, S);
    findTrees(0, S, best);
    return best;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << solve() << endl;
    }
}
