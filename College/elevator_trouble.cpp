#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> state;

void print_queue(int g[],int n) {
    for (int i=0; i<n; i++) {
        cout <<g[i];
    }
    cout<<endl;
}

int main() {
    int f,s,g,u,d;

    cin >> f >> s >> g >> u >> d;
    int *visited = (int *)calloc(f+1, sizeof(int));
    queue<state> q;

    state start = make_pair(s, 0);
    q.push(start);
    visited[s] = 1;
    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        if (cur.first == g) {
            cout << cur.second << endl;
            return 0;
        }

        int up = cur.first + u;
        int down = cur.first - d;
        
        if (0 < up && up <= f && visited[up] == 0) {
            q.push(make_pair(up, cur.second + 1));
            visited[up] = 1;
        }

        if (0 < down && down <= f && visited[down] == 0) {
            q.push(make_pair(down, cur.second + 1));
            visited[down] = 1;
        }
    }

    cout << "use the stairs" << endl;
    return 0;
}
        
