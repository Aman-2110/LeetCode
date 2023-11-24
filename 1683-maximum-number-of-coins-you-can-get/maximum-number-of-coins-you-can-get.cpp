class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), res = 0;
        for(int i = 0 ; i < n / 3 ; i++)
            res += piles[n - 2 - 2*i];
        return res;
    }
};