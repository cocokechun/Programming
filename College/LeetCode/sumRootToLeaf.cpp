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

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;


class Solution {
public:
    void findNums(TreeNode *cur, int num, vector<int> &nums) {
        num *= 10;
        num += cur -> val;
        if (cur->left == NULL && cur->right == NULL) {
            nums.push_back(num);
            return;   
        }
        
        if (cur->left != NULL) {
            findNums(cur->left, num, nums);
        }
        if (cur->right != NULL) {
            findNums(cur->right, num, nums);
        }
        
    }
    
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;
        
        vector<int> nums;
        
        findNums(root, 0, nums);
        
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];    
        }
        return sum;
    }
};

int main() {
    Solution sol;
    TreeNode n1(4);
    TreeNode n2(9);
    TreeNode n3(0);
    TreeNode n4(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    cout << sol.sumNumbers(&n1) << endl;
}

