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
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int count = (int)pow(2, (double)S.size());
       
        vector<vector<int> > res; 
        vector<int> tmp;
        for (int i = 0; i <= count; i++) {
            tmp.clear();
            int num = i;
            int position = 0;
            while (num > 0) {
                if (num % 2 == 1) {
                    tmp.push_back(S[position]);
                }
                position++;
                num /= 2;
            }
            res.push_back(tmp); 
        }

        return res;
    }
};

typedef long long ll;
int main() {
    Solution sol;
}

