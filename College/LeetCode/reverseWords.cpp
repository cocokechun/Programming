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
char res[1000000];

class Solution {
public:
    void reverseWords(string &s) {
        // reverse the whole string
        if (s.size() == 0) {
            return;
        }

        int cursor = 0;
        int end = -1;
        int start = -1;
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] != ' ' && (i+1 == s.size() || s[i+1] == ' ')) {
                end = i;
            }
            if ((i == 0 && s[i] != ' ') || (s[i] != ' ' && s[i-1] == ' ')) {
                start = i;
                for (int j = start; j <= end; j++) {
                    res[cursor] = s[j];
                    cursor++;
                }
                res[cursor] = ' ';
                cursor++;
            }
        }
   
        if (end != -1 && start != -1) { 
            res[cursor-1] = '\0'; 
            for (int i = 0; i < cursor; i++) {
                s[i] = res[i];
            }
            s.resize(cursor-1);
        } else {
            s.resize(0);
        }
    }
};

int main() {
    Solution sol;
    string s = "              ";
    sol.reverseWords(s);
    cout << s << endl;
}
