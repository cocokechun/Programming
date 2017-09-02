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
    void getAllSolutions(int start, string &s, int len, string &tmp, 
                  std::tr1::unordered_set<string> &dict, 
                  vector<string> &res,
                  vector<bool> &possible) {
        if (start == len) {
            int tmp_size = tmp.size();
            tmp.resize(tmp_size-1);
            res.push_back(tmp);
            return;
        } 

        for (int i = start; i < len; i++) {
            if (dict.find(s.substr(start, i-start+1)) != dict.end()
                && possible[i+1]) {
                int res_size = res.size();
                int tmp_size = tmp.size();
                tmp.append(s.substr(start,i-start+1)+" ");
                getAllSolutions(i+1, s, len, tmp,
                                dict, res, possible);
                tmp.resize(tmp_size);
                if (res.size() == res_size) {
                    possible[i+1] = false;
                }
            }
        }
    }
    
    vector<string> wordBreak(string s, std::tr1::unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> possible(n+1, 1);
        vector<string> res;
        string tmp = "";
        getAllSolutions(0, s, n, tmp, dict, res, possible);
        return res;
    }
};

int main() {
    Solution sol;
    string s = "catsanddog";
    std::tr1::unordered_set<string> dict;
    dict.insert("dog");
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    vector<string> res = sol.wordBreak(s, dict);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

}

