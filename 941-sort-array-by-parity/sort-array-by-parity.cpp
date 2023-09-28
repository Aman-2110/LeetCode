class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(!(nums[i] & 1))
                i++;
            else if(nums[j] & 1)
                j--;
            else
                swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};