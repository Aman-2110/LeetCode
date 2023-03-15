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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        bool lastNode = false;
        while(!que.empty()){
            auto t = que.front();
            que.pop();
            if(lastNode){
                if(t->left || t->right)
                    return false;
            }else{
                if(t->left && t->right){
                    que.push(t->left);
                    que.push(t->right);
                }else{
                    lastNode = true;
                    
                    if(t->right)
                        return false;
                    
                    if(t->left)
                        que.push(t->left);
                }
            }
        }
        return true;
    }
};