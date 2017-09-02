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
#define MAX 205
// graph[i][j][c] set to true if from node i to node j there is letter c
bool graph[MAX][MAX][30];
int memo[MAX][MAX][30]; //0 never tried, -1 failed, 1 success
vector<int> nghrs[MAX];

bool dfs(int cur, int dest, char c, bool visited[]) {
    visited[cur] = true;
    if (cur == dest) return true;
    int memo_res = memo[cur][dest][c-'a'];
    if (memo_res == 1) {
        return true;
    } else if (memo_res == -1) {
        return false;
    }


    for (int i = 0; i < nghrs[cur].size(); i++) {
        int to = nghrs[cur][i];
        if (!visited[to] && graph[cur][to][c-'a']) {
            if (dfs(to, dest, c, visited)) {
                memo[cur][dest][c-'a'] = true;
                return true;
            }
        }
    }
    memo[cur][dest][c-'a'] = false;
    return false;
}

void answerQuery(int start, int end) {
    bool visited[MAX];
    bool found = false;

    for (char c = 'a'; c <= 'z'; c++) {
        memset(visited, 0, MAX);
        visited[start] = true;
        int memo_res = memo[start][end][c-'a'];
        if (memo_res == 0) { // never tried need to try
            int tmp = dfs(start, end, c, visited);
            memo[start][end][c-'a'] = (tmp == true) ? 1 : -1;

            if (tmp) {
                cout << c;
                found = true;
            }
        } else if (memo_res == 1) {
            cout << c;
            found = true;
        } else {
            // do nothing, already tried but failed
        }
    }
    if (!found) {
        cout << '-';
    }
    cout << endl;
}

void solve() {
    memset(graph, 0, MAX * MAX * 30);
    memset(memo, 0, MAX * MAX * 30 * sizeof(int));

    int from, to;
    string chars;

    //read graph
    while(1) {
        cin >> from >> to;
        if (from == 0 && to == 0) {
            break;
        }
        cin >> chars;
        for (int i = 0; i < chars.size(); i++) {
            graph[from][to][chars[i]-'a'] = true;
            nghrs[from].push_back(to);
        }
    }

    // read and answer query
    while (1) {
        cin >> from >> to;
        if (from == 0 && to == 0) {
            cout << endl;
            return;
        }
        answerQuery(from, to);
    }
}

int main() {
    int n;
    
    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }
        solve(); 
    }
    return 0;
}

