#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Solution {
public:
    void helper(int dividend, int divisor, int &res, int &remainder) {
        if (dividend == 0) {
            res = 0;
            remainder = 0;
            return;
        }
        bool same_sign = (dividend > 0 && divisor > 0) ||
                         (dividend < 0 && divisor < 0);
        if (abs(dividend) <= abs(divisor)) {
            if (abs(dividend) < abs(divisor)) {
                res = 0;
                remainder = dividend;
            } else {
                res = (same_sign) ? 1 : -1;
                remainder = 0;
            }
            //cout << dividend << " " << divisor << " " << res << " " << remainder << endl;
            return;
        }

        int a = dividend >> 1;
        int b = dividend - a;
        //cout << "a is " << a << endl;
        //cout << "b is " << b << endl;
        int half1 =  (abs(a) < abs(b)) ? a : b;
        int half2 = dividend - half1;
        helper(half1, divisor, res, remainder);
        int extra = remainder + remainder + half2 - half1;
        int extra_res = (abs(extra) >= abs(divisor)) ? 
                        ((same_sign) ? 1 : -1) : 0;
        res = res + res + extra_res;
        remainder = remainder + remainder + half2 - half1;
        if (extra_res != 0) remainder -= divisor;
        //cout << dividend << " " << divisor << " " << res << " " << remainder << endl;
        return;
    }

    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == -2147483648) return 0;
        bool same_sign = (dividend > 0 && divisor > 0) ||
                         (dividend < 0 && divisor < 0);
        
        //bool same_sign = (dividend * divisor > 0);
      
        int res, remainder; 
        helper(dividend, divisor, res, remainder); 
        return res;
    }
};

int main() {
    Solution sol;
    printf("%d\n", sol.divide(12, 1));
    printf("%d\n", sol.divide(-3, 1));
    printf("%d\n", sol.divide(10, 3));
    printf("%d\n", sol.divide(3, 1));
    printf("%d\n", sol.divide(3, 2));
    printf("%d\n", sol.divide(-3, 2));
    printf("%d\n", sol.divide(3, -2));
    printf("%ld\n", (-1010369383)/(-2147483648));
    printf("%d\n", sol.divide(-1010369383, -2147483648));
}
