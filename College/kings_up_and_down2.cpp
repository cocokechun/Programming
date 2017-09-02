#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long answer[21];
    answer[0] = 0;
    answer[1] = 1;
    answer[2] = 2;
    answer[3] = 4;

    long long m[21][21];
    for (long i=0; i<21; i++) {
        for (long j=0; j<21; j++) {
            m[i][j] = 0;
        }
    }

    m[3][2] = 2;

    for (long i=4; i<21; i++) {
        for (long j=2; j<i; j++) {
            long long sum;
            if (j == 2) {
                sum = m[i-1][i-j];
            } else {
                sum += m[i-1][i-j];
            }
            m[i][j] = sum;
        }
    }

    for (long i=3; i<21; i++) {
        answer[i] = 0;
        for (long j=2; j<=i-1; j++) {
            answer[i] += (m[i][j] * j);
        }
    }

    /*for (long i=0; i<21; i++) {
        for (long j=0; j<21; j++) {
            printf("%lld ", m[i][j]);
        }
        printf("\n");
    }*/

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int index, num;
        cin >> index >> num;
        long long res = answer[num];
        cout << index << " " << res << endl;
    }
}

