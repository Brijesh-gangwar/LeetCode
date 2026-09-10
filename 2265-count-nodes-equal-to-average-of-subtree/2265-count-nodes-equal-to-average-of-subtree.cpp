/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int result = 0;

    int findsum(TreeNode* root, int& count) {
        if (root == nullptr)
            return 0;

        count++;

        int left = findsum(root->left, count);
        int right = findsum(root->right, count);

        return root->val + left + right;
    }

    void solve(TreeNode* root) {
        if (root == nullptr)
            return;

        int count = 0;
        int sum = findsum(root, count);

        if (root->val == sum / count)
            result++;

        solve(root->left);
        solve(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return result;
    }
};