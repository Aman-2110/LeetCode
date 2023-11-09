class Solution {
public:
    int countHomogenous(string s) {
        int count = 0, curr = 0, last = 'A', n = s.size(), mod = 1e9 + 7;
        for(char c : s){
            if(last == c){
                curr++;
            }else{
                count = (count + (curr * 1ll * (curr + 1))/ 2) % mod;
                curr = 1;
                last = c;
            }
        }

        return (count + (curr * 1ll * (curr + 1))/ 2) % mod;
    }
};