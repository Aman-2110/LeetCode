class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool increasing, isFirst = true;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] - nums[i - 1] > 0){
                if(isFirst){
                    isFirst = false;
                    increasing = true;
                }
                else if(!increasing)
                    return false;
            }else if(nums[i] - nums[i - 1] < 0){
                if(isFirst){
                    isFirst = false;
                    increasing = false;
                }else if(increasing)
                    return false;
            }
        }

        return true;
    }
};