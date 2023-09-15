class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;

        for(int i = 31 ; i >= 0 ; i--){
            int a = left & (1<<i), b = right & (1<<i);
            if(a & b)
                ans += (1 << i);
            else if(a || b)
                break;
        }

        return ans;
    }
};