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
#include <string>

using namespace std;
typedef long long ll;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        if (len3 != len1 + len2) {
            return false;
        }
       
        bool formed[len1+1][len2+1];
        memset(formed, 0, (len1+1)*(len2+1));
        formed[0][0] = true;
        
        for (int i = 1; i <= len3; i++) {
            for (int j = 0; j <= min(len1, i); j++) {
                if (formed[j][i-1-j]) {
                    if (j < len1 && s1[j] == s3[i-1]) {
                        formed[j+1][i-1-j] = true;
                    } 
                    if (i-1-j < len2 && s2[i-1-j] == s3[i-1]) {
                        formed[j][i-j] = true;
                    }
                }
            }    
        }

        return formed[len1][len2];
    }
};

int main() {
    Solution sol;
    string s1 = "aabcc";
    string s2 = "dbbca";

    cout << sol.isInterleave(s1, s2, "aadbbcbcac") << endl;
    cout << sol.isInterleave(s1, s2, "aadbbbaccc") << endl;
    cout << sol.isInterleave("", "", "") << endl;

    string a1 = "abc";
    string b1 = "def";
    cout << sol.isInterleave(a1, b1, "adefbc") << endl;


}

