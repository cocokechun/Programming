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
#include <tr1/unordered_set>
#include <string>

using namespace std;
typedef long long ll;
class Solution {
public:
    bool wordBreak(string s, std::tr1::unordered_set<string> &dict) {
        int n = s.size();
        bool subs[n+1][n+1];
        memset(subs, 0, (n+1)*(n+1));

        for (int len = 1; len <= n; len++) {
            for (int pos = 0; pos <= n-len; pos++) {
                string sub = s.substr(pos, len);
                if (dict.find(sub) != dict.end()) {
                    subs[pos][len] = true;
                }
                if (len > 1) {
                    for (int sublen = 1; sublen < len; sublen++) {
                        if (subs[pos][sublen] && subs[pos+sublen][len-sublen]) {
                            subs[pos][len] = true;
                        }
                    }
                }
            }
        }
        return subs[0][n];
    }
};
int main() {
    Solution sol;
    string s = "a";
    std::tr1::unordered_set<string> dict;
    cout << sol.wordBreak(s, dict) << endl;
}

