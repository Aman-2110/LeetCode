class Solution {
public:
    set<vector<int>> st;
    void helper(int i, vector<int> &vec, map<int, int> &mp, int n){
        if(i == n){
            st.insert(vec);
        }

        for(auto p : mp){
            if(mp[p.first] > 0){
                vec.push_back(p.first);
                mp[p.first]--;
                helper(i + 1, vec, mp, n);
                vec.pop_back();
                mp[p.first]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        vector<int> vec;
        helper(0, vec, mp, nums.size());
        vector<vector<int>> res(st.begin(), st.end());
        return res; 
    }
};