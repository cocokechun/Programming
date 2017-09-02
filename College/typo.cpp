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

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    char p1 = 0;
    char p2 = 1; 
    char p3 = 2;
    int count = 0;

    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        char c = *it;
        //cout << c << p1 << p2 << p3 << endl;
        if (c == p1) {
            if (c == p2) {
                count ++;
                continue;
            } else {
                if (p2 == p3) {
                    count ++;
                    continue;
                }
            }
        }
        st.push(c);
        p3 = p2;
        p2 = p1;
        p1 = c;
    }
    int len = st.size();
    char res[len + 1];
    res[len] = '\0';
    for (int i = len-1; i >= 0; i--) {
        res[i] = st.top();
        st.pop();
    }
    cout << res << endl; 
    //cout << count << endl;
}
