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
#define ALPHABET_SIZE 128
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charst(ALPHABET_SIZE, 0);        
        int n = s.size();
        int m = t.size();
        for (int i = 0; i < m; i++) {
            charst[t[i]] ++;
        }

        vector<vector<int> > pos(ALPHABET_SIZE);
        vector<int> res(n, n);
        for (int i = n-1; i >= 0; i--) {
            int ch_index = s[i];
            pos[ch_index].push_back(i);
            if (charst[ch_index] > 0) {
                int far = 0;
                for (int j = 0; j < ALPHABET_SIZE; j++) {
                    int size = pos[j].size();
                    int needed = charst[j];
                    if (size < needed) {
                        far = n;
                        break;
                    }
                    if (needed > 0) {
                        far = max(far, pos[j][size-needed]);
                    }
                }
                if (far < n) {
                    res[i] = far;
                }
            }
        }

        int best_start = -1;
        int best_len = n+1;
        for (int i = 0; i < n; i++) {
            if (res[i] < n && res[i]-i+1 < best_len) {
                best_start = i;
                best_len = res[i]-i+1;
            }
        }

        if (best_start != -1) {
            return s.substr(best_start, best_len); 
        } else {
            return "";
        }
    }
};

int main() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << sol.minWindow("abc", "ab") << endl;
}

