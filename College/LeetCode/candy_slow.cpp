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
        int count = 0;
        int size = ratings.size();
        if (size == 1) {
            return 1;
        }

        vector<int> candies(size, 0);

        while (count < size) {
            for (int i = 0; i < size; i++) {
                if (i == 0) {
                    if (candies[i] == 0) {
                        if (ratings[i] <= ratings[i+1]) {
                            candies[i] = 1;
                            count++;
                        } else if (candies[i+1] > 0) {
                            candies[i] = candies[i+1] + 1;
                            count++;
                        }
                    }
                } else if (i == size-1) {
                    if (candies[i] == 0) {
                        if (ratings[i] <= ratings[i-1]) {
                            candies[i] = 1;
                            count++;
                        } else if (candies[i-1] > 0) {
                            candies[i] = candies[i-1] + 1;
                            count++;
                        }
                    }
                } else {
                    if (candies[i] == 0) {
                        if (ratings[i] <= ratings[i-1] && 
                            ratings[i] <= ratings[i+1]) {
                            candies[i] = 1;
                            count++;
                        } else if (ratings[i] <= ratings[i-1] &&
                                   ratings[i] > ratings[i+1]) {
                            if (candies[i+1] > 0) {
                                candies[i] = candies[i+1] + 1;
                                count++;
                            }
                        } else if (ratings[i] <= ratings[i+1] &&
                                   ratings[i] > ratings[i-1]) {
                            if (candies[i-1] > 0) {
                                candies[i] = candies[i-1] + 1;
                                count++;
                            }
                        } else {
                            if (candies[i-1] > 0 && candies[i+1] > 0) {
                                candies[i] = max(candies[i-1], candies[i+1])+1;
                                count++;
                            }
                        }
                    }
                }
            }
        }        

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
    for (int i = 12000; i >= 0; i--) {
        ratings.push_back(i);
    }
    cout << sol.candy(ratings) << endl;
}

