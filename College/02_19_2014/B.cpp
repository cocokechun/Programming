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

#define MAX 1005
typedef struct rect {
    ll lx;
    ll ly; 
    ll rx;
    ll ry;
    bool operator<(const rect& other) const {
        return ry < other.ry;
    }
} rect;

int n;
rect data[MAX];
set<ll> s;

ll area(ll left, ll right) {
    ll top = data[0].ry;

    ll h = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].lx <= left && data[i].rx >= right) {
            if (data[i].ry >= top) {
                h += (data[i].ly - data[i].ry); 
                top = data[i].ly;
            } else {
                if (data[i].ly > top) {
                    h += (data[i].ly - top);
                    top = data[i].ly;
                }
            }
        }
    }
    return (right - left) * h;
}

int main() {
    cin >> n;
   
    for (int i = 0; i < n; i++) {
        cin >> data[i].lx >> data[i].ly >> data[i].rx >> data[i].ry;
        s.insert(data[i].lx);
        s.insert(data[i].rx);
    }

    sort(data, data + n);

    set<ll>::iterator it, left, right;
    it = s.begin();
    left = it;
    it++;

    ll sum = 0;
    for (; it != s.end(); it++) {
        right = it;
        sum += area(*left, *right); 
        left = right;
    }

    cout << sum << endl;
}
