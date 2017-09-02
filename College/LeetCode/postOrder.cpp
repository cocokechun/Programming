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
    void helper(TreeNode *root, vector<int> &res) {
        if (root == NULL) return;

        helper(res->left, res);
        helper(res->right, res);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};

int main() {
    Solution sol;
}

