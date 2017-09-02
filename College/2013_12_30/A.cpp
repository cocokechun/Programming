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
typedef long long ll;

int main() {
    int a, b;
    
    cin >> a >> b;

    if (a < b) {
        cout << a << endl;
        return 0;
    }

    int newcs = a;
    int remains = 0;
    int res = 0;
    int old_newcs;

    while (newcs > 0) {
        res += newcs;
        old_newcs = newcs + remains;
        newcs = (newcs + remains) / b;
        remains = old_newcs % b;
        //printf("old newcs is %d, newcs is %d, remains is %d\n", old_newcs, newcs, remains);
    }

    cout << res << endl;
    return 0;
}
