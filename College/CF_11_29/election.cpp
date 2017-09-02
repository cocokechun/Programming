#include <iostream>
#include <cstdlib>
#include <utility>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;
typedef pair<int, int> pii;

#define MAX_LEN 100010
vector<int> tree[MAX_LEN];
vector<bool> roads[MAX_LEN];
int parents[MAX_LEN];
set<int> s;

int dfs(int p, int k) {
    printf("p is %d, k is %d\n",p, k);
    int counter = 0;
    int size = tree[k].size();
    for (int i = 0; i < tree[k].size(); i++) {
        if (tree[k][i] != p) {
            counter += dfs(k, tree[k][i]);
        } else {
            parent_i = i;
        }
    }
    if (counter == 0 && p > 0 && roads[k][parent_i] == 1) {
        s.insert(k);
        return 1;
    }
    return counter;
}

int find_parents() {
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


int main() {
    int n;
    cin >> n;
   
    int x, y, r; 
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &x, &y, &r);
        tree[x].push_back(y);
        tree[y].push_back(x);
        roads[x].push_back(r-1);
        roads[y].push_back(r-1);
    }

    find_parents();
    int ans = dfs(-1, 1);
    cout << ans << endl;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        printf("%d ", *it);
    }

    printf("\n");
}
