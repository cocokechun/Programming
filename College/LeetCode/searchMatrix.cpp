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
    int lookup(vector<vector<int> > &matrix, int rows, int cols, int index) {
        return matrix[index/cols][index%cols];
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;        
        int m = matrix[0].size();
        
        int low = 0;
        int high = n * m;
        int midNum, mid;
        
        while (low < high) {
            mid = low + (high - low) / 2;
            cout << low  << ' ' << high << ' ' << mid << endl;
            midNum = lookup(matrix, n, m, mid);
            cout << midNum << endl;
            if (midNum == target) {
                return true;
            } else if (midNum < target) {
                low = mid+1;
            } else {
                high = mid;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(1);
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    cout << sol.searchMatrix(matrix, 0) << endl;

}

