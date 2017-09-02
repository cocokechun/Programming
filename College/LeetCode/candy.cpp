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
    int candy(vector<int> &ratings) {
        int size = ratings.size();

        if (size == 1) return 1;
        vector<int> candies(size, 0);

        for (int i = 0; i < size; i++) {
            if (i == 0) {
                candies[i] = 1;
            } else {
                if (ratings[i] > ratings[i-1]) {
                    candies[i] = candies[i-1] + 1;
                } else {
                    candies[i] = 1;
                }
            }
        }

        //cout << candies[0] << ' ' << candies[1] << endl;

        for (int i = size-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }

        //cout << candies[0] << ' ' << candies[1] << endl;

        int res = 0;
        for (int i = 0; i < size; i++) {
            res += candies[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> ratings;
    ratings.push_back(1);
    ratings.push_back(2);
    cout << sol.candy(ratings) << endl;
}

