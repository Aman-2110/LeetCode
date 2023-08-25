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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> res;
        deque<TreeNode*> deq1, deq2;
        deq1.push_back(root);
        bool flag = true;
        while(!deq1.empty() || !deq2.empty()){
            vector<int> temp;
            if(flag){
                for(int i = 0 ; i < deq1.size() ; i++) {
                    temp.push_back(deq1[i]->val);

                    if(deq1[i]->left)
                        deq2.push_front(deq1[i]->left);
                    
                    if(deq1[i]->right)
                        deq2.push_front(deq1[i]->right);
                }
                deq1.clear();
            }else{
                for(int i = 0 ; i < deq2.size() ; i++) {
                    temp.push_back(deq2[i]->val);
                    
                    if(deq2[i]->right)
                        deq1.push_front(deq2[i]->right);

                    if(deq2[i]->left)
                        deq1.push_front(deq2[i]->left);
                }
                deq2.clear();
            }
            flag = !flag;
            res.push_back(temp);
        }
        return res;
    }
};