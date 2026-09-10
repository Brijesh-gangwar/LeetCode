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
    pair<int,int> solve(TreeNode* root) {
        if (root == nullptr)
            return {0,0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int totalsum = root->val + left.first + right.first;
        int totalcount = left.second + right.second + 1;
        
        if((totalsum/totalcount) == root->val)
            result += 1;

        return {totalsum , totalcount};

    }

    int averageOfSubtree(TreeNode* root) {
       auto ans = solve(root);
        return result;
    }
};