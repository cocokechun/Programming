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
ll ninePowers[20];

bool isPower2Minus1(int len) {
    while (len > 0) {
        if (len % 2 == 0) return false;
        len /= 2;
    }
    return true;
}

char findRightChar(int index, char unwanted) {
    int unwantedIndex = unwanted - '0';
    if (index < unwantedIndex) return '0' + index;

    return index + 1 + '0';
}

// assuming s[0] already filled
void recover(string &s, ll K, char unwanted, vector<int> &frees) {
    for (int i = 0; i < frees.size(); i++) {
        int index =frees[i];

        int restLen = frees.size() - (i+1);
        ll multiplier = ninePowers[restLen];
        for (int j = 0; j < 9; j++) {
            if (K <= (j+1) * multiplier) {
                s[index] = findRightChar(j, unwanted);
                K -= j* multiplier;
                break;
            }
        }
    }
}

void solve(ll K) {
    string s;
    cin >> s;

    vector<int> frees; // contains set of indexes that are undetermined (not
                     // including index 0)
    int len = s.size();

    // check length
    if (!isPower2Minus1(len)) {
        cout << -1 << endl;
        return;
    }

    // fill in as many chars as possible
    // all the even indexes have to be same
    char c = '?';
    for (int i = 0; i < len; i += 2) {
        if (s[i] != '?') {
            if (c == '?') {
                c = s[i];
            } else {
                if (s[i] != c) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    if (c == '0') {
        cout << -1 << endl;
        return;
    }
    //if (c == '?') frees.push_back(0);
    if (c != '?') s[0] = c;

    vector<bool> used(10, false);
    for (int i = 1; (1<<i)-1 <= len/2; i++) {
        int startIndex = (1<<i) - 1; 
        c = '?';
        for (int j = startIndex; j < len; j += (1<<(i+1))) {
            if (s[j] != '?') {
                if (c == '?') c = s[j];
                else {
                    if (s[j] != c) {
                        cout << -1 << endl;
                        return;
                    }
                }
            }
        }
        if (c == '?') frees.push_back(startIndex);
        else {
            s[startIndex] = c;
            used[c-'0'] = true;
        }
    }

    vector<char> poss;
    for (int i = 1; i < 10; i++) {
        if (!used[i]) poss.push_back('0'+i);
    }

    ll total = 1;
    if (s[0] == '?') total *= poss.size();
    for (int i = 0; i < frees.size(); i++) {
        total *= 9; // *9 because no adjacent digits can be the same
    }

    if (total < K) {
        cout << -1 << endl;
        return;
    }

    // search the number determine digit by digit
    char chars[9];
    if (s[0] != '?') {
        // generate possible chars for other digits
        recover(s, K, s[0], frees);
    } else {
        int restLen = frees.size();
        ll multiplier = ninePowers[restLen];
        for (int i = 0; i < poss.size(); i++) {
            if (K <= (i+1) * multiplier) {
                s[0] = poss[i];
                K -= i * multiplier;
                // generate possible chars for other digits
                recover(s, K, s[0], frees);
                break;
            }
        }
    }

    // copy chars
    for (int i = 0; i < len; i += 2) {
        s[i] = s[0];
    }

    for (int i = 1; (1<<i)-1 <= len/2; i++) {
        int startIndex = (1<<i) - 1; 
        c = s[startIndex];
        for (int j = startIndex; j < len; j += (1<<(i+1))) {
            s[j] = c;
        }
    }

    cout << s << endl;
    return;
}

int main() {
    ll num = 1;
    for (int i = 0; i < 20; i++) {
        ninePowers[i] = num;
        num *= 9;
    }

    ll n;
    while (cin >> n) {
        if (n == 0) break;
        solve(n);
    }
}
