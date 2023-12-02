class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        cin.tie(0)->sync_with_stdio(0);
        int res = 0;
        vector<int> vec(26, 0);
        for(char c : chars)
            vec[c - 'a']++;

        for(int i = 0 ; i < words.size() ; i++){
            vector<int> temp(26, 0);
            bool flag = true;
            for(int j = 0 ; j < words[i].size() ; j++){
                temp[words[i][j] - 'a']++;
                if(temp[words[i][j] - 'a'] > vec[words[i][j] - 'a']){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res += words[i].size();
        }

        return res;
    }
};