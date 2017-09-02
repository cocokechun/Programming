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
#define MAX 0
#define MIN 1

int calculate(char c, int n, int m) {
    switch (c) {
        case '*':
            return n*m;
        case '+':
            return n+m;
        default:
            return n-m;
    }
}

int choose_best(int a, int b, int type) {
    if (type == MIN) return min(a,b);
    
    return max(a,b);
}

int helper(vector<int> nums, vector<char> signs, int type) {
    int n = signs.size();
    if (nums.size() == 1) {
        return nums[0];
    }

    int best = (type == MAX) ? (1<<31): (~(1<<31));
    vector<int> toPassNums;
    vector<char> toPassSigns;
    int num;
    // player1 starts first
    for (int i = 0; i < n; i++) {
        num = calculate(signs[i], nums[i], nums[i+1]);    
        toPassNums.clear();
        toPassSigns.clear();
        for (int j = 0; j < n; j++) {
            if (j != i) {
                toPassSigns.push_back(signs[j]);
            }
        }

        for (int j = 0; j < n+1; j++) {
            if (j == i) {
                toPassNums.push_back(num);
            } else if (j == i+1) {
                //do nothing
            } else {
                toPassNums.push_back(nums[j]);
            }
        }
   
        int helper_res =  helper(toPassNums, toPassSigns, 1-type);
        best = choose_best(best, helper_res, type);
    }
    return best;
}


void solve() {
    int n;
    cin >> n;
    vector<int> nums;
    vector<char> signs;

    int num;
    char sign;
    for (int i = 0; i < (2*n+1); i++) {
        if ( i % 2 == 0) {
            cin >> num;
            nums.push_back(num);
        } else {
            cin >> sign;
            signs.push_back(sign);
        }
    }

    int r1 = (1<<31);
    int r1_sign_index = -1;
    vector<int> toPassNums;
    vector<char> toPassSigns;
    // player1 starts first
    for (int i = 0; i < n; i++) {
        num = calculate(signs[i], nums[i], nums[i+1]);    
        toPassNums.clear();
        toPassSigns.clear();
        for (int j = 0; j < n; j++) {
            if (j != i) {
                toPassSigns.push_back(signs[j]);
            }
        }

        for (int j = 0; j < n+1; j++) {
            if (j == i) {
                toPassNums.push_back(num);
            } else if (j == i+1) {
                //do nothing
            } else {
                toPassNums.push_back(nums[j]);
            }
        }
   
        int helper_res =  helper(toPassNums, toPassSigns, MIN);
        if (helper_res > r1) {
            r1 = max(r1, helper_res);
            r1_sign_index = i;
        }
    }
    cout << "Player 1 (" << nums[r1_sign_index]<<signs[r1_sign_index]<<nums[r1_sign_index+1]<<") leads to " << r1 << endl;

    int r2 = ~(1<<31);
    // player2 starts first
    int r2_sign_index = -1;
    // player2 starts first
    for (int i = 0; i < n; i++) {
        num = calculate(signs[i], nums[i], nums[i+1]);    
        toPassNums.clear();
        toPassSigns.clear();
        for (int j = 0; j < n; j++) {
            if (j != i) {
                toPassSigns.push_back(signs[j]);
            }
        }

        for (int j = 0; j < n+1; j++) {
            if (j == i) {
                toPassNums.push_back(num);
            } else if (j == i+1) {
                //do nothing
            } else {
                toPassNums.push_back(nums[j]);
            }
        }
   
        int helper_res =  helper(toPassNums, toPassSigns, MAX);
        if (helper_res < r2) {
            r2 = min(r2, helper_res);
            r2_sign_index = i;
        }
    }
    cout << "Player 2 (" << nums[r2_sign_index]<<signs[r2_sign_index]<<nums[r2_sign_index+1]<<") leads to " << r2 << endl;

    
    if (r1 > -r2) {
        cout << "Player 1 wins" << endl;
        return;
    } 
    if (r1 < -r2) {
        cout << "Player 2 wins" << endl;
        return;
    }
    cout << "Tie" << endl;
    return; 
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Case " << (i+1) << ":" <<endl;
        solve();
    }
}

