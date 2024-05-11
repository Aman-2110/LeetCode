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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        TreeNode* curr = root;
        while(curr){
            if(!curr->left){
                preOrder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* itr = curr->left;
                while(itr->right && itr->right != curr)
                    itr = itr->right;
                
                if(!itr->right){
                    itr->right = curr;
                    preOrder.push_back(curr->val);
                    curr = curr->left;
                }else{
                    itr->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return preOrder;
    }
};