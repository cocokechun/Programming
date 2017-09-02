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
    void find(int depth, int n, int k, string &s, 
             vector<int> nums, vector<int> used) {
        if (depth == 0) {
            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    s.push_back('0'+i);
                    return;
                }
            }
        }

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                count ++;
                if (count * nums[depth] >= k) {
                    used[i] = true;
                    s.push_back('0'+i);
                    find(depth-1, n, k-(count-1)*nums[depth], s, nums, used);
                    break;
                }
            }
        }
    }

    string getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }

        vector<int> nums(n+1, 0);
        vector<int> used(n+1, 0);
        nums[0] = 1;
        for (int i = 1; i < n; i++) {
            nums[i] = i * nums[i-1];
        }
        
        string s = "";
        find(n-1, n, k, s, nums, used);
        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.getPermutation(3, 6) << endl;
}



