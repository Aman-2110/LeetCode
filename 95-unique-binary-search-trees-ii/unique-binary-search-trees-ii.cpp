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
    vector<TreeNode*> generateTrees(int e, int s = 1) {
        if(s == e)
            return {new TreeNode(s)};
        
        vector<TreeNode*> res;

        for(int i = s ; i <= e ; i++){
            vector<TreeNode*> lef, rig;
            if(i != s)
                lef = generateTrees(i - 1, s);
            if(i != e)
                rig = generateTrees(e, i + 1);

            if(lef.size() == 0){
                for(auto r : rig){
                    TreeNode* temp = new TreeNode(i);
                    temp->right = r;
                    res.push_back(temp);
                }
                continue;
            }

            if(rig.size() == 0){
                for(auto l : lef){
                    TreeNode* temp = new TreeNode(i);
                    temp->left = l;
                    res.push_back(temp);
                }
                continue;
            }

            for(auto l : lef){
                for(auto r : rig){
                    TreeNode* temp = new TreeNode(i, l, r);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};