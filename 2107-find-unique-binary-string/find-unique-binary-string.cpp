class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> num;
        int n = nums.size();
        
        for(string s : nums)
            num.push_back(stoi(s, 0, 2));

        unordered_set<int> st(num.begin(), num.end());

        for(int i = 0 ; i < n ; i++){
            if(st.find(i) == st.end()){
                string s = "";
                while(i != 0){
                    if(i & 1)
                        s = '1' + s;
                    else
                        s = '0' + s;
                    i /= 2;
                }
                while(s.size() != n){
                    s = '0' + s;
                }
                return s;
            }
        }

        string s = "";
        int i = n;
        while(i != 0){
            if(i & 1)
                s = '1' + s;
            else
                s = '0' + s;
            i /= 2;
        }
        while(s.size() != n){
            s = '0' + s;
        }
        return s;
    }
};