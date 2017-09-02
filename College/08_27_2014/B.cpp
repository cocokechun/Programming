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
    string a, b;
    cin >> a >> b;

    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        bool contains = true;
        for (int j = 0; j < b.size(); j++) {
            if (i+j > a.size() || a[i+j] != b[j]) {
                contains = false;
                break;
            }
        }
        if (contains) res++;
    }
    cout << res << endl;
    return 0;
}
