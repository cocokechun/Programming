#include <iostream>
#include <cstdlib>
#include <utility>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <stack>

using namespace std;
typedef pair<int, int> pii;

#define MAX_LEN 10005
vector<int> tree[MAX_LEN];
int vis[MAX_LEN];
int parents[MAX_LEN];
vector<int> bad_roads[MAX_LEN];
pii levels[MAX_LEN];
map<pii, int> m1;
set<int> s;

int dfs() {
    stack<int> st;
    st.push(1);
    parents[1] = -1;

    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        for (vector<int>::iterator it = tree[cur].begin(); 
                        it != tree[cur].end(); it++) {
            if (*it != parents[cur]) {
                st.push(*it);
                parents[*it] = cur;
            }
        }
    }
}

int find_bad_roads(int n) {
    for (int i = 2; i < n; i++) {
        if (tree[i].size() == 1) {
            int tmp = i;
            int counter = 0;
            int level = 0;
            while (parents[tmp] != 1) {
                counter++;
                if (s.find(make_pair))
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
   
    int x, y, r; 
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d %d", &x, &y, &r);
        tree[x].push_back(y);
        tree[y].push_back(x);
        //roads[x][y] = r-1;
        m1[make_pair(x,y)] = r-1;
        m1[make_pair(y,x)] = r-1;
    }

    dfs(); // find everyone's parents

    for (int i = 1; i < n+1; i++) {
        cout << i << ' ' << parents[i] << endl;
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
}
