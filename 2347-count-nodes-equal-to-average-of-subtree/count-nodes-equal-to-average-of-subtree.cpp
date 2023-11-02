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
    pair<int, int> dfs(TreeNode *root){
        if(!root)
            return {0, 0};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        return {root->val + l.first + r.first, 1 + l.second + r.second};
    }

    void postOrder(TreeNode* root, int &count){
        if(!root)
            return ;

        auto p = dfs(root);

        if(root->val == p.first / p.second)
            count++;

        postOrder(root->left, count);
        postOrder(root->right, count);
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        postOrder(root, count);
        return count;
    }
};