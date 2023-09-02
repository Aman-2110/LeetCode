class Solution {
public:
    void helper(int i, int lastNotPicked, vector<int> &nums, vector<int> &vec, vector<vector<int>> &res){
        if(i == nums.size()){
            res.push_back(vec);
            return;
        }

        helper(i + 1, nums[i], nums, vec, res);
        
        if(lastNotPicked != nums[i]){
            vec.push_back(nums[i]);
            helper(i + 1, lastNotPicked, nums, vec, res);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec;
        vector<vector<int>> res;
        helper(0, -11, nums, vec, res);
        return res;
    }
};