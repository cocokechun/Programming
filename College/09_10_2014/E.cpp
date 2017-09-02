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

int getBase(string s) {
    if (s.size() > 1) {
        return 10;
    } else {
        return s[0] - '0';
    }
}

void convert(int base, int num, vector<int> &digits) {
    if (num == 0) {
        digits.push_back(0);
        return;
    }

    int divend = num;
    while (divend != 0) {
        int remainder = divend % base;
        divend /= base;
        if (remainder < 0) {
            remainder += abs(base);
            divend += 1;
        }
        digits.push_back(remainder);
    }
}

int sToInt(string num) {
    int res = 0;

    for (int i = 0; i < num.size(); i++) {
        if (num[i] == '-') continue;
        res *= 10;
        res += (num[i]-'0');
    }

    if (num[0] == '-') res *= -1;
    return res;
}

void solve(string s, string num) {
    if (s[0] == 't') {
        int base = -getBase(s.substr(3));
        vector<int> digits;
        convert(base, sToInt(num), digits);
        for (int i = digits.size()-1; i >= 0; i--) {
            cout << digits[i];
        }
        cout << endl;
        return;
    } else { //from
        int base = -getBase(s.substr(5));
        int res = 0;
        for (int i = 0; i < num.size(); i++) {
            res *= base;
            res += (num[i] - '0');
        }
        cout << res << endl;
        return;
    }
}

int main() {
    while (1) {
        string s, num;
        cin >> s;
        if (s == "end") {
            break;
        }
        cin >> num;
        solve(s, num);
    }

    return 0;
}
