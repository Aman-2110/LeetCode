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
    void dfs(TreeNode* root, int &count, vector<vector<int>> &adj){
        count++;

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left, count, adj);
        }

        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right, count, adj);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> adj(1e5 + 1);
        vector<bool> vis(1e5 + 1, false);
        int count = 0, c = 0;
        dfs(root, count, adj);

        queue<pair<int, int>> que;
        que.push({start, 0});
        vis[start] = true;
        while(!que.empty()){
            auto [a, b] = que.front();
            que.pop();
            c++;

            if(count == c)
                return b;
            
            for(auto p : adj[a]){
                if(!vis[p]){
                    que.push({p, b + 1});
                    vis[p] = true;
                }
            }
        }

        return 0;
    }
};