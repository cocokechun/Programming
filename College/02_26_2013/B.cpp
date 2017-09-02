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
int A[10000007];

int choose(int n, int k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    int pre_sum = 0;
    int sum = 0; // number of binary numbers so far
    int len = k-1; // length of binary number to look at currently

    while (sum < n) {
        len++;
        pre_sum = sum;
        //cout << pre_sum << endl;
        sum += choose(len-1, len-k);
    }
    
    int m = n - pre_sum;
    //int A[k+1];
    memset(A, 0, sizeof(int) * (k+1));
    //cout << len << endl;
    //cout << m << endl;

    int count = 0;
    int j = 1;
    int num_zero = len - k;

    for (int i = 2; i <= len; i++) {
        if (j > num_zero) {
            break;
        }
        int to_add = choose(len-i, num_zero-j);
        if (m <= count + to_add) {
            A[j] = i;
            j++;
        } else {
            count += to_add;
        }
    }

    j = 1;
    for (int i = 1; i <= len; i++) {
        if (i == A[j]) {
            printf("0");
            j++;
        } else {
            printf("1");
        }
    }
    printf("\n");
}
