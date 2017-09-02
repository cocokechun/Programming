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

int stoi(string s) {
    int res = 0;
    int pow = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        res += pow * (s[i] - '0');
        pow *= 10;
    }
    return res;
}

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int res = 0;        
        stack<int> s;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int b = s.top();
                s.pop();    
                int a = s.top();
                s.pop();    
                s.push(a+b);
            } else if (tokens[i] == "-") {
                int b = s.top();
                s.pop();    
                int a = s.top();
                s.pop();    
                s.push(a-b);
            } else if (tokens[i] == "*") {
                int b = s.top();
                s.pop();    
                int a = s.top();
                s.pop();    
                s.push(a*b);
            } else if (tokens[i] == "/") {
                int b = s.top();
                s.pop();    
                int a = s.top();
                s.pop();    
                s.push(a/b);
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }

};

int main() {
    Solution sol;
    //string array[] = {"4", "13", "5", "/", "+"};
    string array[] = {"2", "1", "+", "3", "*"};
    vector<string> s(array, array+5);
    cout << sol.evalRPN(s) << endl;
}

