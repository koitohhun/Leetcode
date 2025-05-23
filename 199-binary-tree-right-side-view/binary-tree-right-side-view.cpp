/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightViewHelper(root, 0, res);
        return res;
    }

private:
    void rightViewHelper(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;

        if (res.size() == level) {
            res.push_back(node->val);
        }

        rightViewHelper(node->right, level + 1, res);
        rightViewHelper(node->left, level + 1, res);
    }
};