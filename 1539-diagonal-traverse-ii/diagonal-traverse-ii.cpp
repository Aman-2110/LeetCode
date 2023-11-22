class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        cin.tie(0)->sync_with_stdio(0);
        cout.tie(0)->sync_with_stdio(0);
        map<int, vector<int>> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums[i].size() ; j++){
                mp[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> res;
        for(auto p : mp){
            while(p.second.size() != 0){
                res.push_back(p.second.back());
                p.second.pop_back();
            }
        }

        return res;
    }
};