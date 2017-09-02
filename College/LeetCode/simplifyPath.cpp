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
#include <deque>

using namespace std;
typedef long long ll;

class Solution {
public:
    string simplifyPath(string s) {
        if (s.size() <= 1) return s;

        deque<string> de;
        // split words by slash
        int prev = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (i == s.size() || s[i] == '/') {
                string sub = s.substr(prev+1, i-prev-1);
                if (sub == "..") {
                    if (!de.empty()) de.pop_back();
                } else if (sub != "." && sub != "") {
                    de.push_back(sub);
                }
                prev = i;
            }
        }

        // make the result string by words on the deque
        string res = s;
        int count = 0;
        for (int i = 0; i < de.size(); i++) {
            string top = de[i];
            res[count] = '/';
            count++;
            for (int j = 0; j < top.size(); j++) {
                res[count] = top[j];
                count ++;
            }
        }
        if (count == 0) {
            return "/";
        }
        res.resize(count);
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.simplifyPath("/a/b/../c/") << endl;
    cout << sol.simplifyPath("/a/./b/../../c/") << endl;
    cout << sol.simplifyPath("/../") << endl;
    cout << sol.simplifyPath("/home//foo/") << endl;
    cout << sol.simplifyPath("/...") << endl;
    cout << sol.simplifyPath("/.") << endl;
    cout << sol.simplifyPath("/..") << endl;
    cout << sol.simplifyPath("/home/foo/.ssh/../.ssh2/") << endl;
    cout << sol.simplifyPath("/Hhp/..///f/R///FM/DPPv///..//") << endl;
}

