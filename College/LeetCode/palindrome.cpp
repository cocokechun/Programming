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
class Solution {
public:

    bool isPal(string sub) {
        int n = sub.size();
        for (int i = 0; i <= n/2; i++) {
            if (sub[i] != sub[n-1-i])  return false;
        }
        return true;
    }

    void getAll(int start, int len, string &s,
                vector<bool> possible,
                vector<vector<string> > &res, 
                vector<string> &partial) {
        if (start >= len) {
            res.push_back(partial); 
            return;
        }

        for (int end=start; end < len; end++) {
            string sub = s.substr(start, end-start+1);
            if (isPal(sub) && possible[end+1]) {
                partial.push_back(sub);
                int res_size = res.size();
                getAll(end+1, len, s, possible, res, partial);
                partial.pop_back();
                if (res.size() == res_size) {
                    possible[end+1] = false;
                }
            }
        }
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        int n = s.size();
        vector<bool> possible(n+1, 1);       
        vector<string> partial;
        getAll(0, s.size(), s, possible, res, partial);
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string> > res = sol.partition(s);
    cout << "return " << res.size() << endl;
    cout << res[0][0] << ' ' << res[0][1] <<  ' ' << res[0][2] << endl;
    cout << res[1][0] << ' ' << res[1][1] <<  ' ' << endl;
}

