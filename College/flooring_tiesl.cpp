#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main() {
    int n = 2*3*5*7*11*13*17*19;
    int *l = (int *)malloc(sizeof(int) * n);
    map<int,int> m;

    for (int i=1; i<n; i++){
        l[i] = 1;
    }

    for (int i=2; i<n; i++){
        for (int j = i; j < n; j += i) {
            l[j] += 1;
        }
    }

    int factors;
    for (int i = n-1; i > 0; i--) {
        factors = l[i];
        if (factors % 2 == 1) {
            m[factors/2 + 1] = i;
        } else {
            m[factors/2] = i;
        }
    }

    int t;
    while (true) {
        cin >> t;
        if (t == 0) break;
        cout << m[t]<<endl;
    }
    free(l);
}
