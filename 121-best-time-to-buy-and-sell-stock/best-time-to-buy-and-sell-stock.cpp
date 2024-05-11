class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0, buy  = 1e5;

        for(int i = 0 ; i < prices.size() ; i++){
            if(prices[i] < buy){
                buy = prices[i];
            }else{
                maxi = max(prices[i] - buy, maxi);
            }
        }

        return maxi;
    }
};