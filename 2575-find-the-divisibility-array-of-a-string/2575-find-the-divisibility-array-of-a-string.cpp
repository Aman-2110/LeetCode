class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long remainder = 0;
        vector<int> res;
        for(int i = 0 ; i < word.size() ; i++){
            remainder *= 10;
            remainder += (word[i] - '0');
            remainder = remainder % m;
            if(remainder == 0)
                res.push_back(1);
            else
                res.push_back(0);                
        }
        return res;
    }
};