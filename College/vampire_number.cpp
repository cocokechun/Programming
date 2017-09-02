#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void push_chars(vector<int> v, int n) {
    int tmp = n;
    while (tmp > 0) {
        v.push_back(tmp % 10);
        tmp /= 10;
    }
}

int is_v(int n) {
    vector<int> v;
    push_chars(v, n);
    sort(v.begin(), v.end());

    for (int i = 1; i < n; i++) {
        vector<int> p;
        if (i * (n/i) == n) {
            push_chars(p, i)l
            push_chars(p, n/i);
        }
        sort(p.begin(), p.end());
        if (is_v)
    }
}

int main() {
    return 0;
}
