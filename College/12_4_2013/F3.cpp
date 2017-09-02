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
#include <bitset>
#include <set>
using namespace std;

#define MAX 1000005
int t1[MAX];
int t2[MAX];
int t3[2 * MAX];
multiset<int> s;

typedef long long ll;

int solve(int n, int m) {
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        t1[i] = num;
        s.insert(num);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        t2[i] = num;
        s.insert(num);
    }

    for (int i = 0; i < n+m; i++) {
        scanf("%d", &num);
        t3[i] = num;
        s.erase(num);
    }
    
    if (!s.empty()) return 0;

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (counter == n+m) {
            return 0;
        }
        while (t3[counter] != t1[i]) {
            counter ++;
            if (counter == n+m) {
                return 0;
            }
        }
    }

    counter = 0;
    for (int i = 0; i < m; i++) {
        if (counter == n+m) {
            return 0;
        }
        while (t3[counter] != t2[i]) {
            counter ++;
            if (counter == n+m) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        } else {
            if (solve(n, m)) {
                cout << "possible" << endl;
            } else {
                cout << "not possible" << endl;
            }
        }
    }
    return 0;
}
