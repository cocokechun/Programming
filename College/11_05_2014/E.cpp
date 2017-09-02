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
#define MAX 1000005

int find(vector<int> &A, int num) {
    int low = 0;
    int high = A.size();

    while (low < high) {
        int mid = low + (high-low)/2;
        if ((mid == 0 && A[mid] >= num) || (A[mid] >= num && A[mid-1] < num)) {
            return mid;
        } else if (A[mid] < num) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int n;
    cin >> n;

    int m = 0;
    vector<int> A;
    int height;
    for (int i = 0; i < n; i++) {
        cin >> height;
        A.push_back(height);
        m = max(m, height);
    }

    sort(A.begin(), A.end());
    int best = MAX;
    for (int i = 0; i <= m; i++) {
        int num = find(A, i+1);
        if (num >= 0 && num < A.size()) {
            num = A.size() - num;
        }
        int sol = num + i; 
        best = min(best, sol);
    }
    cout << best << endl;
}
