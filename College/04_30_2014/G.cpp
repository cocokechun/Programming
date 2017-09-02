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

#define MAX 1005
using namespace std;
typedef long long ll;
int nums[MAX];

int can_equal_sum(int upper, int m) {
    int sum = 0;
    for (int i = 0; i < upper; i++) {
        sum += nums[i];
    }
    //cout << "sum " << sum << endl;

    int acc = sum;
    for (int i = upper; i < m; i++) {
        acc -= nums[i];
        if (acc == 0) {
            acc = sum;
        }
        if (acc < 0) {
            return -1;
        }
    }

    if (acc > 0 && acc != sum) {
        return -1;
    }
        
    return sum;
}

void find(int index, int m) {
    for (int i = 1; i <= m; i++) {
        int res = can_equal_sum(i, m);
        if (res > 0) {
            cout << index << ' ' << res << endl;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int index, m;
    for (int i = 0; i < n; i++) {
        cin >> index >> m;
        //cout << index << ' '<< m << endl;
        for (int j = 0; j < m; j++) {
            cin >> nums[j];
        }

        find(index, m);
    }

}

