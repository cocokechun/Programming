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
#define MAX 25

int parse(char c) {
    switch (c) {
        case 'T':
            return 10;
        case 'J':
            return 10;
        case 'Q':
            return 10;
        case 'K':
            return 10;
        case 'A':
            return 1;
        default:
            return c-'0';
    }
}

void findBest(int acc,
              vector<int> &nums,
              int &best, int count, int len, int base, int start) {
    if (count == len) {
        if (acc <= 21) best = max(best, acc);
        return;
    }
    if (count == 0 || count == 1) {
        if (count == 1) base ++;
        if (acc+nums[base+count] <= 21) {
            findBest(acc+nums[base+count], nums, best, count+1, len, 
                    base, start);
        }
        if (nums[base+count] == 1 && acc+nums[base+count]+10 <= 21) {
            findBest(acc+nums[base+count]+10, nums, best, count+1, len,
                    base, start);
        }
    } else {
        int index = start + (count-2);
        if (acc+nums[index] <= 21) {
            findBest(acc+nums[index], nums, best, count+1, len,
                    base, start);
        }
        if (nums[index] == 1 && acc+nums[index]+10 <= 21) {
            findBest(acc+nums[index]+10, nums, best, count+1, len,
                    base, start);
        }
    }
}

bool canBelow17(vector<int> &nums, int len1, int len2) {
    // If dealer does not have 17 point or above then should not count this
    // round
    int sum = nums[1] + nums[3];
    for (int i = 0; i < len2; i++) {
        sum += nums[4+len1+i];
    }
    return sum < 17;
}

bool canAbove17(vector<int> &nums, int len1, int len2) {
    // If dealer does not have 17 point or above then should not count this
    // round
    int sum = nums[1] + nums[3];
    sum += (nums[1] == 1) ? 10 : 0;
    sum += (nums[3] == 1) ? 10 : 0;
    for (int i = 0; i < len2; i++) {
        sum += nums[4+len1+i];
        sum += (nums[4+len1+i] == 1) ? 10 : 0;
    }
    return sum < 17;
}


int dealerCanWin(vector<int> &nums, int len1, int len2) {
    // find minimum possible sum for player, if that is bigger than 21, then
    // player must lose
    int sum = nums[0]+nums[2];
    for (int i = 0; i < len1; i++) {
        sum += nums[i+4];
    }
    if (sum > 21) return 1;

    int best1 = 0;
    int best2 = 0;
    // findBest returns the value <= 21 closest to it 
    findBest(0, nums, best1, 0, len1+2, 0, 4);
    findBest(0, nums, best2, 0, len2+2, 1, 4+len1);
    if (len1+2 == 4) {
        cout << len1 << ' ' << len2 << ' ' << best1 << ' ' << best2 << endl;
    }

    // every value of player is above 21
    if (best1 == 0) {
        //cout << len1 << ' ' << len2 << ' ' << best1 << ' ' << best2 << endl;
        return 1;
    }
    // every value of dealer is above 21
    if (best2 == 0) {
        cout << "true" << len1 << ' ' << len2 << ' ' << best1 << ' ' << best2 << endl;
        return 0;
    }
    if (best1 < best2) { 
        cout << "true" << len1 << ' ' << len2 << ' ' << best1 << ' ' << best2 << endl;
        return 1;
    }
        //cout << len1 << ' ' << len2 << ' ' << best1 << ' ' << best2 << endl;
    return 0; 
}

int solve(string s) {
    vector<int> nums;   
    for (int i = 0; i < s.size(); i++) {
        nums.push_back(parse(s[i]));
    }

    for (int i = 0; i <= s.size()-4; i++) { // number of cards player draws
        int dealerwin = false; 
        for (int j = 0; j <= s.size()-4-i; j++) {// number of cards dealer draws
            if (canAbove17(nums, i, j)) {
                if (dealerCanWin(nums, i, j)) {
                    dealerwin = true;
                    break;
                }
            }
            if (canBelow17(nums, i, j)) {
                continue;
            }
        }
        if (!dealerwin) {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    while (cin >> s) {
        if (s == "JOKER") {
            break;
        }
        if (solve(s)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
