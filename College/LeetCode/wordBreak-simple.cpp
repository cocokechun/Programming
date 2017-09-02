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
        bool subs[n];
        memset(subs, 0, (n+1));

        for (int end = 0; end < n; end++) {
            if (dict.find(s.substr(0, end+1)) != dict.end()) {
                subs[end] = true;
                continue;
            }
            for (int start = 0; start < end; start++) {
                if (subs[start] && dict.find(s.substr(start+1, end-start)) !=
                    dict.end()) {
                    subs[end] = true;
                    break;
                }
            }
        }
        
        return subs[n-1];
    }
};
int main() {
    Solution sol;
    string s = "ab";
    std::tr1::unordered_set<string> dict;
    dict.insert("a");
    dict.insert("b");
    cout << sol.wordBreak(s, dict) << endl;
}

