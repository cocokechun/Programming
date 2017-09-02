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

using namespace std;
typedef long long ll;

int pop(stack<int> a, stack<int> b) {
    int ele = a.top();
    a.pop();
    b.push(ele);
}

int solve(int n, int m) {
    stack<int> t1;
    stack<int> t1_left;
    stack<int> t2;
    stack<int> t2_left;
    stack<int> t3;
    stack<int> t3_left;

    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        t1.push(num);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        t2.push(num);
    }

    for (int i = 0; i < n+m; i++) {
        scanf("%d", &num);
        t3.push(num);
    }

    vector<int> from(m+n);
    from.assign(m+n, 0);

    int counter = 0;
    while (1) {
        if (t3.empty()) {
            return 1;
        }
        int ele = t3.top();
        t3.pop();
        if (ele == t1.top() && from[counter] == 0) {
            t3_left.push(ele);
            pop(t1, t1_left);
            from[counter] = 1;
            counter++;
        } else if (ele == t2.top()) {
            if (from[counter] < 2) {
                t3_left.push(ele);
                pop(t2, t2_left);
                from[counter] = 2;
                counter++;
            }
        } else {
            if (t3_left.empty()) {
                return 0;
            } else {
                counter--;
                //pop(t3_left, t3);
                t3.push(ele);
                if (from[counter] == 1) {
                    pop(t1_left, t1);
                } else if (from[counter] == 2) {
                    pop(t2_left, t2);
                }
                from[counter] = 0;
            }
        }
    }
}

int main() {
    while (1) {
        int n, m;
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

