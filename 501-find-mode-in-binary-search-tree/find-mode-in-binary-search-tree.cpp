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
    void preorder(TreeNode* root, unordered_map<int, int> &mp){
        if(!root)
            return;

        mp[root->val]++;
        preorder(root->left, mp);
        preorder(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        preorder(root, mp);
        int maxi = 0;
        vector<int> res;

        for(auto p : mp){
            if(p.second > maxi){
                res.clear();
                res.push_back(p.first);
                maxi = p.second;
            }else if(p.second == maxi)
                res.push_back(p.first);
        }

        return res;
    }
};