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
    pair<int, int> postOrder(TreeNode* root, int &count){
        if(!root)
            return {0, 0};

        auto l = postOrder(root->left, count);
        auto r = postOrder(root->right, count);

        if(root->val == (l.first + r.first + root->val)/(l.second + r.second + 1))
            count++;
        
        return {l.first + r.first + root->val, l.second + r.second + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        postOrder(root, count);
        return count;
    }
};