class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        
        for(int i = left ; i <= right ; i++){
            if(st.find(words[i][0]) != st.end() && st.find(words[i][words[i].size() - 1]) != st.end())
               count++;
        }
               
        return count;
    }
};