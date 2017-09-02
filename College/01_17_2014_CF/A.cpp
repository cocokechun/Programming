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

int main() {
    string a, b;
    cin >> a >> b;
    int n = 0;
    int m = 0;
    int k = b.size();

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != '|') {
            n++;
        } else {
            break;
        }
    }
    m = a.size()-1-n;

    int diff = abs(n-m);
    if (k < diff) {
        printf("Impossible\n");
        return 0;
    }

    if ((k-diff) % 2 == 1) {
        printf("Impossible\n");
    } else {
        int equal = (k-diff) / 2;
        //cout << diff << endl;

        // printf left part
        for (int i = 0; i < n; i++) {
            printf("%c", a[i]);
        }
        for (int i = 0; i < equal; i++) {
            printf("%c", b[i]);
        }
        if (n+equal < (n+m+k) / 2) {
            for (int i = 0; i < diff; i++) {
                printf("%c", b[2*equal+i]);
            }
        }
        printf("|");

        // printf right part
        for (int i = 0; i < m; i++) {
            printf("%c", a[n+1+i]);
        }
        for (int i = 0; i < equal; i++) {
            printf("%c", b[equal+i]);
        }
        if (m+equal < (n+m+k) / 2) {
            for (int i = 0; i < diff; i++) {
                printf("%c", b[2*equal+i]);
            }
        }
        printf("\n");
    }
}
