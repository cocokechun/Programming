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

int parity(int ar[], int n) {
    set<int> s;
    set<int>::iterator it_hi;
    int res;
    for (int i=0; i<n; i++) {
        it_hi = s.upper_bound(ar[i]);
        int num = ar[i];
        res += distance(s.upper_bound(num), s.end()); 
        s.insert(num);
    }
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

