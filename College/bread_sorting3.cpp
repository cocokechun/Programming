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

using namespace std;
const int MAX = 100005;

int tree[MAX];

void push1 (int a) {
    a --;
    for (int x = a; x > 0; x -= (x & -x)) {
        tree [x] ++;
    }
}

int pop1 (int a) {
    int res = 0;
    for (int x = a; x < MAX; x += (x & -x)) {
        res += tree [x];
    }
    return res;
}


int parity(int ar[], int n) {
    memset(tree, 0, sizeof(tree));
    int res = 0;
    for (int i=0; i<n; i++) {
        int num = ar[i];
        res += pop1(num);
        push1(num);
    }
    //cout << "Res is " << res << endl; 
    return res % 2;
}

int main() {
    int n;
    cin >> n;
    int start[n];
    int end[n]; 

    for (int i=0; i<n; i++) {
        scanf("%d", &start[i]);
    }

    for (int i=0; i<n; i++) {
        scanf("%d", &end[i]);
    }

    if (parity(start, n) == parity(end, n)) {
        cout << "Possible" <<endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}

