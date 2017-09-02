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

char find(int n, int k, int len) {
    if (k == 0) {
        if (n == 1) return 'm';
        else return 'o';
    }

    int a = (len - (1+k+2)) / 2;
    int b = a + 1 + k + 2;

    if (n <= a) {
        return find(n, k-1, a);
    } else if (n == a+1) {
        return 'm'; 
    } else if (n <= b) {
        return 'o';
    } else {
        return find(n-b, k-1, a);
    }
}

int main() {
    int n;
    cin >>n ;

    int k = 0;
    int len = 3;
    while (len < n) {
        k++;
        len = 2 * len + 1 + (k + 2);
    }

    cout << find(n, k, len) << endl;
}

