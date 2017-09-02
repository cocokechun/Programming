#include <stdio.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        
        int res = 0;
        bool positive = (dividend > 0);
        //bool same_sign = (dividend * divisor > 0);
        bool same_sign = (dividend > 0 && divisor > 0) ||
                         (dividend < 0 && divisor < 0);
        
        while (1) {
            dividend = (same_sign) ? (dividend - divisor) : (dividend + divisor);

            res = (same_sign) ? (res + 1) : (res - 1);
            //res ++;
            
            if (dividend == 0) {
                break;
            }
            
            if ((dividend > 0) != positive) {
                res = (same_sign) ? (res - 1) : (res + 1);
                //res--;
                break;
            } 
        }
        return res;
    }
};

int main() {
    Solution sol;
    printf("%d\n", sol.divide(3, 1));
    printf("%d\n", sol.divide(3, 2));
    printf("%d\n", sol.divide(-3, 2) == -3/2);
    printf("%d\n", sol.divide(3, -2) == 3/-2);
}
