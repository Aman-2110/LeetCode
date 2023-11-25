class Solution {
public:
    set<vector<int>> st;
    void helper(vector<int> &vec, map<int, int> &mp, int n){
        if(vec.size() == n){
            st.insert(vec);
        }

        for(auto p : mp){
            if(mp[p.first] > 0){
                vec.push_back(p.first);
                mp[p.first]--;
                helper(vec, mp, n);
                vec.pop_back();
                mp[p.first]++;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        cin.tie(0)->sync_with_stdio(false);
        cout.tie(0)->sync_with_stdio(false);
        map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        vector<int> vec;
        helper(vec, mp, nums.size());
        vector<vector<int>> res(st.begin(), st.end());
        return res; 
    }
};