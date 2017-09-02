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
int nums[12];
int perms[12];
bool selected[12];

// return true if it is really true or cannot be determined yet
bool sum_pass(int k) {
    if (k < 6) {
        return true;
    }
    int expected = perms[0] + perms[1] + perms[2] + perms[3];
    if (k >= 6) {
        int tmp = perms[3]+perms[4]+perms[5]+perms[6];
        if (tmp != expected) return false;
    }
    if (k >= 8) {
        int tmp = perms[6]+perms[7]+perms[8]+perms[0];
        if (tmp != expected) return false;
    }
    if (k >= 11) {
        int tmp = perms[2]+perms[4]+perms[9]+perms[11];
        if (tmp != expected) return false;
    }
    if (k >= 10) {
        int tmp = perms[1]+perms[8]+perms[9]+perms[10];
        if (tmp != expected) return false;
    }
    if (k >= 11) {
        int tmp = perms[5]+perms[7]+perms[10]+perms[11];
        if (tmp != expected) return false;
    }
    return true;
}

int find_perm(int k) {
    //cout << "k " << k << endl;
    if (k == 12) {
        if (sum_pass(k)) {
            return 1;
        }
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < 12; i++) {
        if (!selected[i]) {
            perms[k] = nums[i];
            selected[i] = true;
            if (sum_pass(k)) {
                sum += find_perm(k+1);
            }
            selected[i] = false;
        }
    }
    return sum;
}

int solve() {
    memset(selected, 0, 12); 
    return find_perm(0);
}

int main() {
    while (1) {
        memset(nums, 0, 12*sizeof(int));
        for (int i = 0; i < 12; i++) {
            cin >> nums[i];
            if (nums[i] == 0) return 0;
        }
        cout << solve()/12 << endl;
    }
}
