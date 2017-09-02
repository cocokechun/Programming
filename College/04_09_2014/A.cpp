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
#define MAX 100005
int acc[MAX]; // left - right
int A[MAX]; // A[i] is the min of temp[i] before i
int B[MAX]; // B[i] is the min of temp[i] after i and including itself
int temp[MAX];

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int left = 0;
    int right = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        temp[i] = left - right;
        //cout << temp[i] << endl;
    }

    int best_min = temp[0];
    A[0] = 0;
    for (int i = 1; i < n; i++) {
        A[i] = best_min;
        best_min = min(best_min, temp[i]);
    }

    best_min = temp[n-1];
    for (int i = n-1; i >= 0; i--) {
        best_min = min(best_min, temp[i]);
        B[i] = best_min;
    }

    int count = 0;
    int l, r, lower;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            l = left - 1;
            r = right + 1;
            lower = 2;
        } else {
            r = right - 1;
            l = left + 1;
            lower = -2;
        }
        if (l == r && A[i] >= 0 && B[i] >= lower) {
            count++;
        }
    }
    
    cout << count << endl;
}
