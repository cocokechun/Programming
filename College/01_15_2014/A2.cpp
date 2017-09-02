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
#include <sstream>

using namespace std;
typedef long long ll;

int convert(string a, int b) {
    int res = 0;
    int power = 1;

    for (int i = a.size()-1; i >= 0; i--) {
        res += (a[i] - '0') * power;
        power *= b;
    }

    return res;
}

int main() {
    int n, m;
    string s1, s2;

    cin >> s1 >> s2;
    //cout << convert(s1, 2) << endl;
    //cout << convert(s2, 3) << endl;
    
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            string a = s1;
            string b = s2;
            a[i] = (s1[i] == '0') ? '1' : '0';
            //cout << a << endl;

            for (int k = 0; k < 3; k++) {
                if (s2[j] != '0' + k) {
                    b[j] = '0' + k;
                    //cout << b << endl;
                    if (convert(a, 2) == convert(b, 3)) {
                        cout << convert(a,2) << endl;
                        return 0;
                    }
                }
            }
            //cout << endl;
        }
    }
}
