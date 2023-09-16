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
    vector<vector<int>> res;
    void helper(TreeNode* root, int targetSum, vector<int> &curr){
        if(!root)
            return;

        curr.push_back(root->val);

        if(root->val == targetSum && !root->left && !root->right){
            res.push_back(curr);
        }else{
            helper(root->left, targetSum - root->val, curr);
            helper(root->right, targetSum - root->val, curr);
        }

        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        helper(root, targetSum, curr);
        return res;
    }
};