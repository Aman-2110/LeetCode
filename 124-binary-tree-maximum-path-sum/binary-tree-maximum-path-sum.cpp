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
    int maxi;
    int helper(TreeNode* root) {
        if(!root)
            return 0;
        
        int leftSum = max(0, helper(root->left));
        int rightSum = max(0, helper(root->right));
        maxi = max(root->val + leftSum + rightSum, maxi);
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        helper(root);
        return maxi;
    }
};