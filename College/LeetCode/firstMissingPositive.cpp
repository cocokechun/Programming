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
class Solution {
public:
    void swap(int A[], int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n) {
            while (A[i] > 0 && A[i] <= n 
                   && i != A[i]-1 && A[i]-1 != A[A[i]-1]-1 ) {
                swap(A, i, A[i]-1);
            }
            i++;
        }

        for (int i = 0; i < n; i++) {
            if (i != A[i]-1) {
                return i+1;
            }
        }
        return n+1;
    }
};

int main() {
    Solution sol;
    int A[4] = {3, 4, -1 ,1};
    int B[3] = {0, 1, 2};
    int C[4] = {1,2,3,4};
    cout << sol.firstMissingPositive(A, 4) << endl;
    cout << sol.firstMissingPositive(B, 3) << endl;
    cout << sol.firstMissingPositive(C, 4) << endl;
}

