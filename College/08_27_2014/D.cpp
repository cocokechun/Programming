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
#define MAX 1000005
bool visited[MAX];
vector<int> graph[MAX];

int main() {
    int n, m;
    cin >> n >> m;
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    queue<int> levels;
    q.push(1);
    levels.push(1);
    visited[1] = true;
    int cur, cur_level;

    while (!q.empty()) {
        cur = q.front();
        cur_level = levels.front();
        q.pop();
        levels.pop();
        if (cur == n) {
            cout << cur_level<< endl;
            return 0;
        }
        
        for (vector<int>::iterator it = graph[cur].begin(); 
             it != graph[cur].end();
             it++) {
            if (!visited[*it]) {
                q.push(*it);
                levels.push(cur_level+1);
                visited[*it] = true;
            }
        }
    }

    return 0;
}
