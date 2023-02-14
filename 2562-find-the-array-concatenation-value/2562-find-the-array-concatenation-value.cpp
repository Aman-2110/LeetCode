class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long count = 0;
        int left = 0 , right = nums.size() - 1;
        while(left < right){
            int temp = nums[right];
            int temp2 = 0;
            while(temp != 0){
                temp2++;
                temp /= 10;
            }
            count += (nums[right] + pow(10, temp2)*nums[left]);
            left++;
            right--;
        }
        
        if(left == right)
            count += nums[left];
        
        return count;
    }
};