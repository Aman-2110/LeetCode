class Solution {
public:
    int countOdds(int low, int high) {
        int t = high - low;
        if( t % 2 )
            return (t + 1) / 2;
        else 
            return high % 2 ? t/2 + 1: t/2;
    }
};