class Solution {
public:
    long long appealSum(string s) {
        vector<int> vec(26, -1);
        long res = 0, n = s.size();

        for(int i = 0 ; i < n ; i++){
            if(vec[s[i] - 'a'] == -1)
                res += (i + 1)*(n - i);
            else
                res += (i - vec[s[i] - 'a'])*(n - i);
            vec[s[i] - 'a'] = i;
        }
        
        return res;
    }
};