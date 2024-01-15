class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        cin.tie(0)->sync_with_stdio(false);
        cout.tie(0)->sync_with_stdio(false);
        vector<vector<int>> res(2);
        map<int, pair<int, int>> mp;
        for(auto p : matches){
            mp[p[0]].first++;
            mp[p[1]].second++;
        }

        for(auto p : mp){
            if(p.second.second == 0)
                res[0].push_back(p.first);
            else if(p.second.second == 1)
                res[1].push_back(p.first);
        }

        return res;
    }
};