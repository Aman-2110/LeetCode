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
    void inorder(TreeNode* root, int &maxi, int &currNum, int &currStreak, vector<int> &res){
        if(!root)
            return;

        inorder(root->left, maxi, currNum, currStreak, res);

        int num = root->val;

        if(currNum == num)
            currStreak++;
        else{
            currNum = num; 
            currStreak = 1;
        }

        if(currStreak > maxi){
            res.clear();
            maxi = currStreak;
        }
        
        if(currStreak == maxi)
            res.push_back(num);

        inorder(root->right, maxi, currNum, currStreak, res);
    }
    vector<int> findMode(TreeNode* root) {
        int maxi = 0, currNum = -1e6, currStreak = 0;
        vector<int> res;
        inorder(root, maxi, currNum, currStreak, res);
        return res;
    }
};