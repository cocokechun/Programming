#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int solve(char cs[], int n);

int solve() {
    int n, l, r, q1, q2;
    cin >> n >> l >> r >> q1 >> q2;
    
    long long *nums = (long long*)calloc(n, sizeof(long long));
    int sum_w = 0;
    for (int i=0; i<n; i++) {
        cin >> nums[i];
        sum_w += nums[i];
    }

    long long min_so_far = sum_w * r + (n-1) * q2;
    int base_energy = sum_w * r;
    int total_energy;
    for (int i=0; i<n; i++) {
        base_energy = base_energy - nums[i]*r + nums[i]*l; 
        if (i < n/2) {
            total_energy = base_energy + max(0, n-2*(i+1)-1) * q2;
        } else {
            total_energy = base_energy + max(0, n-2*(n-1-i)-1) * q1; 
        }
        if (total_energy < min_so_far) {
            min_so_far = total_energy;
        }
    }
    free(nums);
    return min_so_far;
}

int main() {
    int result = solve();

    cout<<result<<endl;
    return 0;
}
