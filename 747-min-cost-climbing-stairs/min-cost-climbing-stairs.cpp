class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i;
        for(i = 2 ; i < cost.size() ; i++)    
            cost[i] += min(cost[i-1], cost[i-2]);
        return min(cost[i-1], cost[i-2]);
    }
};