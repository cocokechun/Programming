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

using namespace std;
typedef long long ll;
#define SIZE 26

int solve(string a, string b) {
    int a_size = a.size();
    int b_size = b.size();
    if (a_size != b_size) {
        return 0;
    }
    int lower[SIZE];
    int upper[SIZE];
    memset(lower, 0, SIZE * sizeof(int));
    memset(upper, 0, SIZE * sizeof(int));

    for (int i = 0; i < a_size; i++) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            lower[a[i] - 'a'] ++;
        } else {
            upper[a[i] - 'A'] ++;
        }
    }

    for (int i = 0; i < b_size; i++) {
        if (b[i] >= 'a' && b[i] <= 'z') {
            lower[b[i] - 'a'] --;
        } else {
            upper[b[i] - 'A'] --;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (lower[i] != 0) {
            return 0;
        }
        if (upper[i] != 0) {
            return 0;
        }
    }
    return 1; 
}

int main() {
    string a;
    string b;
    int tn = 0;

    while (1) {
        tn ++;
        cin >> a >> b;
        if (a.compare("END") == 0 && b.compare("END") == 0) {
            break; 
        }
        if (solve(a, b)) {
            printf("Case %d: same\n", tn);
        } else {
            printf("Case %d: different\n", tn);
        }
    }
    return 0;
}
