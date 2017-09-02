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
#define MAX 1005
int nums[MAX];
int A[MAX];
int B[MAX]; 
vector<int> nghrs[MAX];

void solve(int n, int m) {
    memset(A, 0, MAX * sizeof(int));
    memset(B, 0, MAX * sizeof(int));
    memset(nums, 0, MAX * sizeof(int));

    for (int i = 0; i < n; i++) {
        nghrs[i].clear();
    }

    int k, tmp;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        A[i] += nums[i];
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> tmp;
            nghrs[i].push_back(tmp);
            A[tmp] += nums[i];
        }
    }
    
    /*for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;*/

    int dead = 0;
    while (1) {
        for (int i = 0; i < n; i++) {
            B[i] = A[i];
        }

        for (int i = 0; i < n; i++) {
            if (B[i] >= 0 && B[i] < m) {
                for (int j = 0; j < nghrs[i].size(); j++) {
                    if (A[nghrs[i][j]] > 0) {
                        A[nghrs[i][j]] -= nums[i];
                    }
                }
                dead++;
                A[i] = -1;
            }
        }

        if (dead == 0) break;
        dead = 0;
    }

    int count = 0, sum = 0; 
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            count ++;
            sum += nums[i];
        }
    }
   
    cout << count << ' ' << sum << endl; 
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        solve(n, m);
    }
}
