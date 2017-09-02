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
int tree[MAX];
int num[MAX];
int n;

void update(int p, int v) {
    for (; p < MAX; p += p&(-p)) tree[p] += v;
}

void update2(int a, int b, int v) {
    update(a, v);
    update(b+1, -v);
}

int query(int b) {
    int sum = 0;
    for(; b > 0; b -= b&(-b))   sum += tree[b];
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    int low, up;

    for (int i = 1; i <= n; i++) {
        tree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> low >> up;
        update2(low, up, 1);
    }

    for (int i = 1; i <= n; i++) {
        num[i] = query(i);
    }

    sort(num+1, num+n+1);
    /*for (int i = 1; i <= n; i++) {
        cout << num[i] << ' ';
    }
    cout << endl;*/

    cout << num[n/2+1] << endl;
}
