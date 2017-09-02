#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

long long fact(int n) {
    long long res = 1;
    while (n > 0) {
        res *= n;
        n--;
    }
    return res;
}

long long choose(long long n, long long k) {
    if (k == 0) {
        return 1;
    }
    return fact(n) / (fact(k) * fact(n-k));
}


int main() {
    long long answers[21];

    memset(answers, 0, 21 * sizeof(long long));
    answers[1] = 1;
    answers[2] = 2;
    answers[3] = 4;


    for (int i=4; i<21;i++) {
        long long res = 0;
        for (int j=0; j<i; j++) {
            if (j == 0 || j == i-1) {
                res += (answers[i-1]/2);
            } else if (j == 1 || j == i-2) {
                res  += (choose(i-1,1) * answers[i-2] / 2);
            } else {
                res += (choose(i-1,j)*answers[j]/2 * answers[i-1-j]/2);
            }
        }
        answers[i] = res;
    }

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int index, num;
        cin >> index >> num;
        long long res = answers[num];
        cout << index << " " << res << endl;
    }
}

