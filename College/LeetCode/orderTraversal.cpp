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

    void process(queue<TreeNode *> &from, queue<TreeNode *> &to, 
                 vector<int> &level) {
        while (!from.empty()) {
            TreeNode *front = from.front();
            level.push_back(front->val);
            if (front->left != NULL) {
                to.push(front->left);
            }
            if (front->right != NULL) {
                to.push(front->right);
            }
            from.pop();
        }
        return;
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        vector<vector<int> > res;

        if (root == NULL) return res;

        q1.push(root);
        vector<int> level;
        while (!q1.empty() || !q2.empty()) {
            level.clear();
            if (!q1.empty()) {
                process(q1, q2, level);
            } else {
                process(q2, q1, level);
            }
            if (!level.empty()) {
                res.push_back(level);
            }
        } 
        return res;
    }
};

int main() {
    Solution sol;
}
