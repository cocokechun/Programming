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

int toNum(string s) {
    int n = 0;
    int power = 1;

    for (int i = s.size()-1; i >= 0; i--) {
        n += (s[i] - '0') * power;
        power *= 2;
    }
    return n;
}

void toBin(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 2);
        n /= 2;
    }

    //cout << v.size() << endl;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main() {
    string s;
    cin >> s;
    int n = 17 * toNum(s);
    toBin(n);
}
