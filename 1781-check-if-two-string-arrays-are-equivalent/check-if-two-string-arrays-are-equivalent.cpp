class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, i_1 = 0, j = 0, j_1 = 0, m = word1.size(), n = word2.size();
        while(i != m && j != n){
            if(word1[i][i_1] == word2[j][j_1]){
                if(i_1 == word1[i].size() - 1){
                    i++;
                    i_1 = 0;
                }else{
                    i_1++;
                }

                if(j_1 == word2[j].size() - 1){
                    j++;
                    j_1 = 0;
                }else{
                    j_1++;
                }  
            }else
                return false;
        }

        return i == m && j == n;
    }
};