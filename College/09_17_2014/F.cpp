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

#define MAX 40005
using namespace std;
typedef long long ll;
int tree[MAX];
int min_tree[MAX];

void update(int p, int v) {
    for (; p < MAX; p += p&(-p)) tree[p] += v;
}

void update2(int a, int b, int v) {
    update(a, v);
    update(b+1, -v);
}

int query(int b) {
    int sum = 0;
    // need equal sigh? not sure
    for(; b >0; b -= b&(-b))   sum += tree[b];
    return sum;
}

int getSum(int left, int right) {
    if (left == 0) {
        return query(right);
    }
    return query(right) - query(left-1);
}

typedef struct Roof {
    int x1;
    int y1;
    int x2;
    int y2;
    int lowx;
    int lowy;
    int area;
    int index;
    int res;
    Roof(int a,int b,int c,int d, int i):x1(a), y1(b), x2(c), y2(d), area(abs(c-a)), index(i) {
        if (b < d) {
            lowx = a;
            lowy = b;
        } else {
            lowx = c;
            lowy = d;
        }
    }
} Roof;

// from high to low
bool cmp(Roof a, Roof b) {
    return min(a.y1, a.y2) > min(b.y1, b.y2);
}

bool cmp_index(Roof a, Roof b) {
    return a.index < a.index;
}
vector<Roof> roofs;

int main() {
    int n;
    cin >> n;

    int a,b,c,d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        roofs.push_back(Roof(a,b,c,d,i)); 
    }

    sort(roofs.begin(), roofs.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << roofs[i].lowx << ' ' << roofs[i].lowy << endl;
    }

    for (int i = 0; i < n; i++) {
        update(roofs[i].lowx, roofs[i].area);

        cout << getSum(roofs[i].x1+1, roofs[i].x2) << endl;
    }

    /*sort(roofs.begin(), roofs.end(), cmp);
    for (int i = 0; i < n; i++) {
    }*/

    return 0;
}
