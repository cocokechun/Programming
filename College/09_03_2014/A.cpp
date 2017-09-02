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
    double r, w, l;

    int index = 1;
    while (1) {
        cin >> r >> w >> l;
        if (r == 0) {
            return 0;
        }

        if ((w/2) * (w/2) + (l/2) * (l/2) <= r * r) {
            cout << "Pizza "  << index << " fits on the table." << endl;
        } else {
            cout << "Pizza " << index << " does not fit on the table." << endl;
        }
        index ++;
    }
}

