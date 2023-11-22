class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        cin.tie(0)->sync_with_stdio(0);
        cout.tie(0)->sync_with_stdio(0);
        vector<vector<int>> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums[i].size() ; j++){
                if(i + j == mp.size())
                    mp.push_back({nums[i][j]});
                else
                    mp[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> res;
        for(int i = 0 ; i < mp.size() ; i++){
            for(int j = mp[i].size() - 1 ; j >= 0 ; j--){
                res.push_back(mp[i][j]);
            }
        }

        return res;
    }
};