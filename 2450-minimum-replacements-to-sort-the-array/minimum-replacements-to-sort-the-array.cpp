class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long last = nums.back(), res = 0, n = nums.size();

        for(int i = n - 2 ; i >= 0 ; i--){
            if(last >= nums[i]){
                last = nums[i];
            }else{
                if(nums[i] % last){
                    long long k = nums[i]/last + 1;
                    long long low = 1, high = last - 1, mid;
                    while(low <= high){
                        mid = low + (high - low)/2;
                        if(nums[i] - k * mid < 0)
                            high = mid - 1;
                        else if(nums[i] - k*mid < k){
                            low = mid;
                            break;
                        }else {
                            low = mid + 1;
                        }
                    }
                    res += k - 1;
                    last = low;
                }else{
                    res += nums[i]/last - 1;
                }
            }
        }
        return res;
    }
};