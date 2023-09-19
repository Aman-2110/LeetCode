class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i : nums){
            if(st.find(i) != st.end())
                return i;
            st.insert(i);
        }
        return -1;
    }
};