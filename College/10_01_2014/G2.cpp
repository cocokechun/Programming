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

int eval(vector<int> &v) {
    int sum = 0;
    int As = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if (v[i] == 1) {
            As ++;
        }
    }

    while (sum < 21) {
        if (sum + 10 <= 21 && As > 0) {
            sum += 10;
            As --;
        } else {
            break;
        }
    }

    return sum;
}

int playerCanWin(int a, int b) {
    if (a > 21) return false;
    if (b > 21) return true;
    if (a >= b ) return true;
    return false; 
}

int solve(string s) {
    vector<int> nums;   
    for (int i = 0; i < s.size(); i++) {
        nums.push_back(parse(s[i]));
    }

    vector<int> pcards;
    pcards.push_back(nums[0]);
    pcards.push_back(nums[2]);

    vector<int> dcards;
    for (int i = 0; i <= s.size()-4; i++) { // number of cards player draws
        if (i > 0) {
            pcards.push_back(nums[4+i-1]);
        }
        int player = eval(pcards);
        for (int j = 0; j <= s.size()-4-i; j++) {// number of cards dealer draws
            dcards.clear();
            dcards.push_back(nums[1]);
            dcards.push_back(nums[3]);
            for (int k = 0; k < j; k++) {
                dcards.push_back(nums[4+i+k]);
            }
            int dealer = eval(dcards);
            if (dealer >= 17) {
                if (playerCanWin(player, dealer)) {
                    return true;
                }
                // Once dealers' cards are above 17, he cannot draw anymore
                break;
            }
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
