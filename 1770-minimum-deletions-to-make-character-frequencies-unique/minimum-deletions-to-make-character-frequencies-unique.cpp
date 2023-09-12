class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char c : s)
            mp[c]++;
        
        vector<int> vec;
        for(auto p : mp)
            vec.push_back(p.second);

        sort(vec.begin(), vec.end(), greater<int>());
        int last = vec[0], count = 0;
        for(int i = 1 ; i < vec.size() ; i++){
            if(vec[i - 1] == 0){
                count += vec[i];
                vec[i] = 0;
            }else if(vec[i - 1] <= vec[i]){
                count += vec[i] - vec[i - 1] + 1;
                vec[i] = vec[i - 1] - 1;
            }
        }
        return count;
    }
};