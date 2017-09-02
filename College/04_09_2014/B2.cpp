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
#include <limits>

using namespace std;
typedef long long ll;
#define MAX 35
int farm[MAX][MAX];
int routes[MAX*MAX][MAX*MAX];
int n;

bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int to(int i, int j) {
    int res = i * n + j;
    return res;
}

int main() {
    int a, b;
    cin >> n >> a >> b;
    //cout << n << a << b;

    int m = n * n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            routes[i][j] = 1000000 * 900;
        }
    }
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
                    routes[to(i,j)][to(i-1,j)] = a; 
                } else {
                    routes[to(i,j)][to(i-1,j)] = b; 
                }
            }
            if (is_valid(i+1,j)) {
                if (farm[i][j] == farm[i+1][j]) {
                    routes[to(i,j)][to(i+1,j)] = a; 
                } else {
                    routes[to(i,j)][to(i+1,j)] = b; 
                }
            }
            if (is_valid(i,j-1)) {
                if (farm[i][j] == farm[i][j-1]) {
                    routes[to(i,j)][to(i,j-1)] = a; 
                } else {
                    routes[to(i,j)][to(i,j-1)] = b; 
                }
            }
            if (is_valid(i,j+1)) {
                if (farm[i][j] == farm[i][j+1]) {
                    routes[to(i,j)][to(i,j+1)] = a; 
                } else {
                    routes[to(i,j)][to(i,j+1)] = b; 
                }
            }
        }
    }

    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (routes[i][k]+routes[k][j] < routes[i][j]) {
                    routes[i][j] = routes[i][k] + routes[k][j];
                }
            }
        }
    }

    int best = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i != j ) best = max(best, routes[i][j]);
        }
    }

    cout << best << endl;
}
