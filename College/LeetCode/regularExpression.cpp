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

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*s == '\0') {
            if (*p == '\0') return true;
            if (*(p+1) == '*') {
                return isMatch(s, p+2);
            }
            return false;
        }
        
        if (*p == '\0') {
            return *s == '\0';
        }
        
        if (*(p+1) == '*') {
            bool match = true;
            for (int i = 0;;i++) {
                if (match && isMatch(s+i, p+2)) return true;
                if (*(s+i) == '\0') break;
                match &= ((*(s+i) == *p) || (*p == '.'));
            }
            return false;
            
        } else {
            if (*p == '.') {
                return isMatch(s+1, p+1);
            } else {
                return (*s == *p) && isMatch(s+1, p+1);
            }
        }
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("aa","a") << ' ' << 0 << endl; 
    cout << sol.isMatch("aa","aa") << ' ' << 1 << endl; 
    cout << sol.isMatch("aaa","aa") << ' ' << 0 << endl; 
    cout << sol.isMatch("aa", "a*") << ' '  << 1 << endl; 
    cout << sol.isMatch("aa", ".*") << ' ' << 1 << endl; 
    cout << sol.isMatch("ab", ".*") << ' ' << 1 << endl; 
    cout << sol.isMatch("aab", "c*a*b") <<  ' ' << 1 << endl; 
    cout << sol.isMatch("aab", "a*ba") << ' ' << 0 << endl; 
    cout << sol.isMatch("aa", "a*") << ' ' << 1 << endl; 
    cout << sol.isMatch("a", "ab*") << ' ' << 1 << endl; 
    cout << sol.isMatch("", "c*c*") << ' ' << 1 << endl; 
    cout << sol.isMatch("a", ".*..a*") << ' ' << 0 << endl; 
}
