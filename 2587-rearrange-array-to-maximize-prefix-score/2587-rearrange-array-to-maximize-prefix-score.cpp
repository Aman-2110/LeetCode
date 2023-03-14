class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long count = 0, sum = 0;
        for(int i : nums){
            sum += i;
            if(sum > 0)
                count++;
            else
                break;
        }
        return count;
    }
};