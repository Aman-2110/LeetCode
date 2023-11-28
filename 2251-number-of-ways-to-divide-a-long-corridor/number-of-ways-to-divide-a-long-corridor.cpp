class Solution {
public:
    int numberOfWays(string corridor) {
        int count = 0;
        for(auto c : corridor)
            if(c == 'S')
                count++;

        if(count & 1 || count == 0)   
            return 0;

        int s = 0, p = 0, res = 1, mod = 1e9 + 7;
        for(char c : corridor){
            if(s == 2){
                if(c == 'S'){
                    s = 1;
                    res = (res * (p + 1ll))%mod;
                    p = 0;
                }else{
                    p++;
                }
            }else if(c == 'S'){
                s++;
            }
        }

        return res;
    }
};