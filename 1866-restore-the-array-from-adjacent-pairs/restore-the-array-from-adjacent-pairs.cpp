class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        cin.tie(0)->sync_with_stdio(false);
        cout.tie(0)->sync_with_stdio(false);
        unordered_map<int, vector<int>> mp;
        for(auto &v : adjacentPairs){
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }

        int root = -1;
        for(auto &[key, value] : mp){
            if(value.size() == 1){
                root = key;
                break;
            }
        }

        vector<int> res;
        res.push_back(root);
        int prev = root;
        root = mp[root][0];
        res.push_back(root);

        while(mp[root].size() != 1){
            for(int &i : mp[root]){
                if(i != prev){
                    res.push_back(i);
                    prev = root;
                    root = i;
                    break;
                }
            }
        }
        return res;
    }
};