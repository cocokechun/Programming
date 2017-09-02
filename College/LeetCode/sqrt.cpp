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
    int sqrt(int x) {
        if (x <= 1) return x;
        
        ll low = 1;
        ll high = x;
        ll mid;

        while (high - low > 1) {
            mid = low + (high-low) / 2;
            if (mid * mid <= x) {
                low = mid;
            } else {
                high = mid;
            }
        }       

        return low;
    }
};

int main() {
    Solution sol;
    cout << sol.sqrt(2147395599) << endl;
}

