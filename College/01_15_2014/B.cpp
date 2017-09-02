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

using namespace std;
typedef pair<int, int> pii;
#define MAX 50005
pii data[MAX];

int main() {
    int n;
    cin >> n;

    int x, y;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        data[i] = make_pair(x, y);
        s.insert(y);
    }
    int types = s.size();

    sort(data, data+n);

    for (int i = 0; i < n; i++) {
        set<int> s;
        s.insert(data[i].second);
        if (s.size() == types) {
        }
        for (int j = i+1; j < n; j++) {
            if () {
            }
        }
    }
}

