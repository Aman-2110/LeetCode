class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pre(n + 1, 0), suff(n + 1, 0);
        for(int i = 0 ; i < n ; i++){
            pre[i + 1] = pre[i] + nums[i];
            suff[i + 1] = suff[i] + nums[n - 1 - i];
        }

        if(pre[n] < x) 
            return -1;

        int i = 0, j = lower_bound(suff.begin(), suff.end(), x) - suff.begin(), mini = INT_MAX;

        while(i <= n && pre[i] <= x){
            if(pre[i] + suff[j] == x){
                mini = min(i + j, mini);
                i++;
                j--;
            }else if(pre[i] + suff[j] > x)
                j--;
            else
                i++;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};


// 0 1 2 6 8  11
// 0 3 6 9 10 11