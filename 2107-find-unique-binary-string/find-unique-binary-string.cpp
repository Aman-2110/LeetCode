class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        
        for(string s : nums)
            st.insert(stoi(s, 0, 2));

        for(int i = 0 ; i < n ; i++){
            if(st.find(i) == st.end()){
                string s = "";
                while(i != 0){
                    if(i & 1)
                        s.push_back('1');
                    else
                        s.push_back('0');
                    i /= 2;
                }
                while(s.size() != n){
                    s.push_back('0');
                }
                reverse(s.begin(), s.end());
                return s;
            }
        }

        string s = "";
        int i = n;
        while(i != 0){
            if(i & 1)
                s.push_back('1');
            else
               s.push_back('0');
            i /= 2;
        }
        while(s.size() != n){
            s.push_back('0');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};