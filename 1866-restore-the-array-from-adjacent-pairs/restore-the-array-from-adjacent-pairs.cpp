class Solution {
public:
    void dfs(int root, int prev, vector<int> &res, unordered_map<int, vector<int>> &mp){
        res.push_back(root);
        for(auto child : mp[root]){
            if(child != prev)
                dfs(child, root, res, mp);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for(auto v : adjacentPairs){
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }

        int root = -1;
        for(auto [key, value] : mp){
            if(value.size() == 1){
                root = key;
                break;
            }
        }

        vector<int> res;
        dfs(root, -1e6, res, mp);
        return res;
    }
};