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

bool isFree(string a, string b) {
    string s, l;
    if (a.size() < b.size()) {
        s = a;
        l = b;
    } else {
        s = b;
        l = a;
    }
    //cout << s << ' ' << l << endl;

    bool isPrefix = true; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != l[i]) {
            isPrefix = false;
            break;
        }
    }
    //cout << "isPrefix " << isPrefix << endl;

    bool isSuffix = true; 
    for (int i = 0; i < s.size(); i++) {
        if (s[s.size()-1-i] != l[l.size()-1-i]) {
            isSuffix = false;
            break;
        }
    }
    //cout << "isSuffix " << isSuffix << endl;

    return (!isPrefix) & (!isSuffix);
}

int main() {
    int n;
    cin >> n;

    string a, b, c;
    for (int i = 0; i < n; i++) {
        bool free = true;
        cin >> a >> b >> c;

        free &= isFree(a,b); 
        free &= isFree(a,c); 
        free &= isFree(b,c); 
        if (free) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

