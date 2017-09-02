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
#define MAX 100000000
int vams[MAX];

bool isGood(int x, int y) {
    int counts[10];
    memset(counts, 0, 10*sizeof(int));
    int n = x * y;

    while (n > 0) {
        counts[n%10] ++;
        n /= 10;
    }

    while (x > 0) {
        counts[x%10] --;
        x /= 10;
    }

    while (y > 0) {
        counts[y%10] --;
        y /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (counts[i] != 0) {
            return false;
        }
    }
    return true;
}

bool isVam(int a) {
    for (int i = 1; i * i <= a; i++) {
        int j = a/i;
        if ((i * j == a) && isGood(i, j)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;

    while (cin >> n) {
        if (n == 0) return 0;
        for (int i = n; ; i++) {
            if (isVam(i)) {
                cout << i << endl;
                break;
            }
        }
    }
}

