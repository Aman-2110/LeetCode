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
    long total;
    void helper(TreeNode *root, long targetSum, long currSum, bool picked = true){
        if(targetSum == currSum && picked)
            total += 1;

        if(!root)
            return;

        helper(root->left, targetSum, currSum + 0ll + root->val);
        helper(root->right, targetSum, currSum + 0ll + root->val);

        if(currSum == 0 && !picked){
            helper(root->left, targetSum, 0, false);
            helper(root->right, targetSum, 0, false);
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        total = 0;
        helper(root, targetSum, 0, false);
        return total/2;
    }
};