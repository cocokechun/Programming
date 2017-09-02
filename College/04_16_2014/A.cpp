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

#define MAX 50005
using namespace std;
typedef long long ll;
int xs[MAX];

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int acc = 0;
    for (int i = 1; i < n; i++) {
        if (s[i-1] == '(' && s[i] == '(') {
            acc++;
        }
        xs[i] = acc;
        //cout << xs[i] << ' ';
    }
    //cout << endl;

    int sum = 0;
    for (int i = 2; i < n; i++) {
        if (s[i-1] == ')' && s[i] == ')') {
            sum += xs[i-2];
        }
    }
    cout << sum << endl;
}

