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

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int count = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (right > left) {
            s[i] = '(';
            left ++;
            right--;
            count ++;
        }
    }
    int res = count + (left - right) / 2;
    cout << res << endl;
}
