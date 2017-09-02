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

int main() {
    string a;
    string b;
    cin >> a >> b;

    string c = a;
    for (int i = a.size()-1; i >= 0; i--) {
        if (a[i] == 'z' || a[i] == b[i] || a[i]+1 == b[i]) {
            continue;
        } else {
            c[i] = a[i]+1;
            cout << c << endl;
            return 0;
        }
    }
    cout << "No such string" << endl;
    return 0;
}

