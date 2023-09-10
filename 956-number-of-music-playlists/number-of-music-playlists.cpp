class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int currGoal, long uniq, int k, int n, int goal, vector<vector<int>> &dp){
        if(currGoal == goal){
            if(uniq == n)
                return 1;
            else
                return 0;
        }

        if(dp[currGoal][uniq] != -1) 
            return dp[currGoal][uniq];

        long count = 0;

        if(uniq != n)
            count = (count + (n - uniq)*helper(currGoal + 1, uniq + 1, k, n, goal, dp))%mod;
        
        if(uniq > k)
            count = (count + (uniq - k)*helper(currGoal + 1, uniq, k, n, goal, dp))%mod;

        return dp[currGoal][uniq] = count;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector dp(goal + 1, vector<int> (n + 1, -1));
        return helper(0, 0, k, n, goal, dp);
    }
};