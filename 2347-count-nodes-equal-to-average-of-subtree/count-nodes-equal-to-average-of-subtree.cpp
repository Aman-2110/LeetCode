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
    int total;
    int sum(TreeNode *root){
        if(!root)
            return 0;

        auto l = sum(root->left);
        auto r = sum(root->right);

        return root->val + l + r;
    }

    int count(TreeNode *root){
        if(!root)
            return 0;

        auto l = count(root->left);
        auto r = count(root->right);

        return 1 + l + r;
    }

    void preOrder(TreeNode* root){
        if(!root)
            return ;

        auto s = sum(root);
        auto c = count(root);

        if(root->val == s / c)
            total++;

        preOrder(root->left);
        preOrder(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        total = 0;
        preOrder(root);
        return total;
    }
};