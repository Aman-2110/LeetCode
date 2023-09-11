class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> mp;
        for(int i = 0 ; i < g.size() ; i++){
            if(mp.find(g[i]) != mp.end()){
                if(mp[g[i]].size() == g[i]){
                    res.push_back(mp[g[i]]);
                    mp.erase(g[i]);
                }
            }
            mp[g[i]].push_back(i);
        }

        for(auto p : mp)
            res.push_back(p.second);
            
        return res;
    }
};