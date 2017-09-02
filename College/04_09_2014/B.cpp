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
#include <vector>

using namespace std;
typedef long long ll;
#define MAX 31
typedef struct point {
    int x;
    int y;
    int w;
} point;
int farm[MAX][MAX];
vector<struct point> G[MAX][MAX];
int routes[MAX][MAX];
int n;


class CompareEdge {
public:
    bool operator()(point& t1, point& t2) // t2 has highest prio than t1 if t2 is earlier than t1
    {
        return t2.w < t1.w;
    }
};

void dijkstra(int i, int j) {
    //cout << "enter" << endl;
    bool visited[MAX][MAX];
    memset(visited, false, MAX * MAX);
    memset(routes, 0, MAX * MAX);

    priority_queue<point, vector<point>, CompareEdge> pq;
    point p = {i, j, 0};
    pq.push(p);

    while (!pq.empty()) {
        point best = pq.top();
        cout << best.x << ' ' << best.y << ' ' << best.w << endl;
        if (!visited[best.x][best.y]) {
            routes[best.x][best.y] = best.w;
            visited[best.x][best.y] = true;

            // update pq
            // Update distance of the neighbors
            for (vector<point>::iterator it = G[best.x][best.y].begin();
                 it != G[best.x][best.y].end(); it++) {
                if (!visited[it->x][it->y]) {
                    point tmp = {it->x,it->y,routes[best.x][best.y]+it->w};
                    pq.push(tmp);
                }
            }
        }
    }
    return;
}

bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int main() {
    int a, b;
    cin >> n >> a >> b;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            farm[i][j] = (s[j] == '(') ? 0 : 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_valid(i-1,j)) {
                if (farm[i][j] == farm[i-1][j]) {
                    point p = {i-1, j, a};
                    G[i][j].push_back(p);
                } else {
                    point p = {i-1, j, b};
                    G[i][j].push_back(p);
                }
            }
            if (is_valid(i+1,j)) {
                if (farm[i][j] == farm[i+1][j]) {
                    point p = {i+1, j, a};
                    G[i][j].push_back(p);
                } else {
                    point p = {i+1, j, b};
                    G[i][j].push_back(p);
                }
            }
            if (is_valid(i,j-1)) {
                if (farm[i][j] == farm[i][j-1]) {
                    point p = {i, j-1, a};
                    G[i][j].push_back(p);
                } else {
                    point p = {i, j-1, b};
                    G[i][j].push_back(p);
                }
            }
            if (is_valid(i,j+1)) {
                if (farm[i][j] == farm[i][j+1]) {
                    point p = {i, j+1, a};
                    G[i][j].push_back(p);
                } else {
                    point p = {i, j+1, b};
                    G[i][j].push_back(p);
                }
            }
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dijkstra(i,j);
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    best = max(best, routes[k][l]);
                }
            }
        }
    }
    cout << best << endl;
}

