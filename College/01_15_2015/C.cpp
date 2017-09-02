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

#define MAX 4000005
#define ADDER 2000000
#define neginf 0x80000000
using namespace std;

typedef struct Side {
    int x;
    int upper;
    int lower;
    int cx;
    int cy;
    bool left; // whether it is left side of a square
    bool operator<(const Side& other) const {
        if (x == other.x) {
            return !left;
        }
        return x < other.x;
    }
} Side; 

typedef long long ll;
vector<Side> sides;
int tree[2*MAX];
int lazy[2*MAX];
int n, k;

int calculate_area(int x1, int y1, int x2, int y2) {
    int a = min(x1, x2);
    int b = max(x1, x2);
    int c = min(y1, y2);
    int d = max(y1, y2);
    int width = a+k/2 - (b-k/2);
    int height = c+k/2 - (d-k/2);
    return width * height;
}

void update_tree(int node, int a, int b, int i, int j, int value) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];

        if (a!=b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (a > b || a > j || b < i) {
        return;
    }

    if (a >= i && b <= j) {
        tree[node] += value;

        if (a!=b) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }

        return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(node*2+1, 1+(a+b)/2, b, i, j, value);

    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query_tree(int node, int a, int b, int i, int j) {
    if (a > b || a > j || b < i) {
        return neginf;
    }

    if (lazy[node] != 0) {
        tree[node] += lazy[node];

        if (a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (a >= i && b <= j) {
        return tree[node];
    }

    int q1 = query_tree(node*2, a, (a+b)/2, i, j);
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

    int res = max(q1,q2);
    return res;
}

int main() {
    cin >> n >> k;

    int cx, cy;
    Side s;
    for (int i = 0; i < n; i++) {
        cin >> cx >> cy;
        cx += ADDER;
        cy += ADDER;

        s.x = cx - k/2;
        s.left = true;
        s.upper = cy + k/2 - 1;
        s.lower = cy - k/2;
        s.cx = cx; s.cy = cy;
        sides.push_back(s);
        s.x = cx + k/2;
        s.left = false;
        sides.push_back(s);
    }

    sort(sides.begin(), sides.end());
    memset(tree, 0, 2 * MAX * sizeof(int));
    memset(lazy, 0, 2 * MAX * sizeof(int));
    bool seen = false;
    int best = 0;
    int prex, prey;
    
    for (int i = 0; i < sides.size(); i++) {
        if (sides[i].left) {
            update_tree(1, 0, MAX-1, sides[i].lower, sides[i].upper, 1);
            if (query_tree(1, 0, MAX-1, sides[i].lower, sides[i].upper) >= 2) {
                if (seen) {
                    cout << -1 << endl;
                    return 0;
                } else {
                    prex = sides[i].cx;
                    prey = sides[i].cy;
                }
                seen = true;
            }
        } else {
            if (query_tree(1, 0, MAX-1, sides[i].lower, sides[i].upper) >= 2) {
                best = calculate_area(prex, prey, sides[i].cx, sides[i].cy);
            }
            update_tree(1, 0, MAX-1, sides[i].lower, sides[i].upper, -1);
        }
    }

    if (seen) {
        cout << best << endl;
    } else {
        cout << 0 << endl;
    }
}
