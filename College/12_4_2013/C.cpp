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
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    string s;
    while (cin >> s) {
        int size = s.size();
        vector<bool> needed;
        needed.assign(size, 1);
        stack<int> st;
        for (int i = 0; i < size; i++) {
            switch (s[i]) {
                case '(':
                    st.push(i);
                    break;
                case '+':
                    st.push(-1);
                    break;
                case ')':
                    int plus = 0;
                    while (st.top() < 0) {
                        plus = 1;
                        st.pop();
                    }
                    int pre = st.top();
                    st.pop();
                    if (plus) {
                        if ((pre-1 >= 0) && (s[pre-1] == ')' || islower(s[pre-1]))) {
                            continue;
                        }
                        else if ((i+1 < size) && (s[i+1] == '(' || islower(s[i+1]))) {
                            continue;
                        } else {
                            needed[i] = false;
                            needed[pre] = false;
                            st.push(-1);
                        }
                    } else {
                        needed[i] = false;
                        needed[pre] = false;
                    }
            }
        }
        for (int i = 0; i < size; i++) {
            if (needed[i]) {
                printf("%c", s[i]);
               //cout << s[i];
            }
        }
        printf("\n");
        //cout << endl;
    }
}

