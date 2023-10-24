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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> res;
        while(!que.empty()){
            int n = que.size(), maxi = INT_MIN;
            for(int i = 0 ; i < n ; i++){
                auto t = que.front();
                que.pop();
                maxi = max(maxi, t->val);
                if(t->left)
                    que.push(t->left);
                if(t->right)
                    que.push(t->right);
            }
            res.push_back(maxi);
        }
        return res;
    }
};