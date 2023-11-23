class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        cin.tie(0)->sync_with_stdio(0);
        cout.tie(0)->sync_with_stdio(0);
        vector<bool> res;
        int n = l.size();
        for(int i = 0 ; i < n ; i++){
            int a = INT_MAX, last = INT_MIN;
            unordered_set<int> st;
            for(int j = l[i] ; j <= r[i] ; j++){
                a = min(nums[j], a);
                last = max(nums[j], last);
                st.insert(nums[j]);
            }
            
            bool flag = false;
            if((last - a) % (r[i] - l[i]) == 0){
                int d = (last - a) / (r[i] - l[i]);
                
                while(a != last){
                    if(st.find(a) == st.end())
                        break;
                    a += d;
                }
            }

            res.push_back(a == last);
        }

        return res;
    }
};