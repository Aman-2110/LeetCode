class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> res = nums;

        sort(res.begin(), res.end());
        int n = nums.size(), c = 0;
        
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != res[i])
                break;
            c++;
        }

        if(c == n)
            return 0;

        for(int i = n - 1 ; i >= 0 ; i--){
            if(nums[i] != res[i])
                break;
            c++;
        }

        return n - c;


    }
};