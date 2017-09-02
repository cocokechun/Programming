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
#define MAX 100000000
int vams[MAX];

int convert(vector<int> &perms, int start, int end) {
    if (perms[0] == 0) {
        return 0;
    }
    int res = 0;
    for (int i = start; i <= end; i++) {
        res *= 10;
        res += perms[i];
    }
    return res;
}

bool find_perm(vector<int> &digits, 
               vector<bool> &selected, 
               vector<int> &perms,
               int k, int a) {
    if (k == digits.size()) {
        if (digits.size() == 1) return false;

        for (int i = 0; i < digits.size()-1; i++) {
            if (convert(perms, 0, i) * 
                convert(perms, i+1, perms.size()-1) == a) {
                return true;
            }
        }
        return false;
    }

    for (int i = 0; i < digits.size(); i++) {
        if (!selected[i]) {
            perms[k] = digits[i];
            selected[i] = true;
            if (find_perm(digits, selected, perms, k+1, a)) return true;
            selected[i] = false;
        }
    }
    return false;
}

bool isVam(int a) {
    int b = a;
    vector<int> digits;
    while (b > 0) {
        digits.push_back(b % 10);
        b /= 10;
    }
    vector<bool> selected(digits.size(), 0);
    vector<int> perms(digits.size(), 0);

    return find_perm(digits, selected, perms, 0, a);
}

int main() {
    int n;
    for (int i = 0; i < MAX; i++) {
        vams[i] = -1;
    }

    while (cin >> n) {
        if (n == 0) return 0;
        for (int i = n; ; i++) {
            if (vams[i] != -1) {
                if (vams[i]) {
                } else {
                }
            } else {
                if (isVam(i)) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}

