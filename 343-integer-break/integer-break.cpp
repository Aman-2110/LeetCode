class Solution {
public:
    int integerBreak(int n) {
        double maxi = 0;
        for(int i = 2 ; i <= n ; i++){
            int l = n / i, r = n % i;
            maxi = max(maxi, pow(l, i - r)*pow(l + 1, r));
        }
        return maxi;
    }
};