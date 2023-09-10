class Solution {
public:
    int countOrders(int n) {
        int curr = 1, mod = 1e9 + 7;
        
        for(int i = 2 ; i <= n ; i++)
            curr = (curr*1ll*(2*i - 1 + (2*i - 1)*(i - 1)))%mod;
        
        return curr;
    }
};