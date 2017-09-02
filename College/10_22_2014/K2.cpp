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
#define MAX 10005
vector<int> A[MAX];
char Alabels[MAX];
int Asizes[MAX];
vector<int> B[MAX];
char Blabels[MAX];
int Bsizes[MAX];

int findSizes(vector<int> tree[], int sizes[], int cur,
                      vector<pii> &subs) {
    if (tree[cur].size() == 0) {
        sizes[cur] = 1;
        subs.push_back(make_pair(cur, 1));
        return 1;
    }

    int count = 1;
    vector<int> nghrs = tree[cur];
    for (int i = 0; i < nghrs.size(); i++) {
        count += findSizes(tree, sizes, nghrs[i], subs);
    }
    sizes[cur] = count;
    subs.push_back(make_pair(cur, count));
    return count;
}

bool cmp(pii a, pii b) {
    return a.second < b.second;
}

bool cmpTrees(int a, int b, map<pii, bool> &M) {
    if (M.find(make_pair(a,b)) != M.end()) {
        return M[make_pair(a,b)];
    }

    if (Asizes[a] != Bsizes[b]) {
        M[make_pair(a,b)] = false;
        return false;
    }
    if (Alabels[a] != Blabels[b]) {
        M[make_pair(a,b)] = false;
        return false;
    }

    if (A[a].size() != B[b].size()) {
        M[make_pair(a,b)] = false;
        return false;
    }

    for (int i = 0; i < A[a].size(); i++) {
        if (cmpTrees(A[a][i], B[b][i], M) == false) {
            M[make_pair(a,b)] = false;
            return true;
        }
    }
    M[make_pair(a,b)] = true;
    return true;
}

int solve() {
    int n, m;
    cin >> n >> m;

    char type;
    int p;
    memset(Alabels, 0, MAX);
    memset(Blabels, 0, MAX);
    memset(Asizes, 0, MAX*sizeof(int));
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

    vector<pii> Asubs;
    vector<pii> Bsubs;
    findSizes(A, Asizes, 0, Asubs);
    findSizes(B, Bsizes, 0, Bsubs);
   
    sort(Asubs.begin(), Asubs.end(), cmp);
    sort(Bsubs.begin(), Bsubs.end(), cmp); 

    /*for (int i = 0;i < n; i++) {
        cout << Asubs[i].first << ' ' << Asubs[i].second << endl;
    }

    for (int i = 0;i < m; i++) {
        cout << Bsubs[i].first << ' ' << Bsubs[i].second << endl;
    }*/
    int pt = 0;
    int best = 0;
    map<pii, bool> M;
    for (int i = 0; i < n; i++) {
        if (Bsubs[pt].second < Asubs[i].second) {
            while (pt < m && Bsubs[pt].second < Asubs[i].second) {
                pt++;
            }
            if (pt == m) {
                break;
            }
        }

        for (int j = pt; j < m; j++) {
            if (Asubs[i].second < Bsubs[j].second) {
                break;
            }
            if (cmpTrees(Asubs[i].first, Bsubs[j].first, M)) {
                best = max(best, Asubs[i].second);
            }
        }
    }
    return best;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << solve() << endl;
    }
}
