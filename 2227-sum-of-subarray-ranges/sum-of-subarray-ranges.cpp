class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> left_max(n), right_max(n), left_min(n), right_min(n);
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                right_max[st.top()] = i - 1;
                st.pop();
            }
            st.push(i);
            while(i == (n - 1) && !st.empty()){
                right_max[st.top()] = i;
                st.pop();
            }
        }

        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                left_max[st.top()] = i + 1;
                st.pop();
            }
            st.push(i);
            cout << st.size() << endl;
            while(i == 0 && !st.empty()){
                left_max[st.top()] = i;
                st.pop();
            }
        }

        long long res = 0;
        for(int i = 0 ; i < n ; i++)
            res += nums[i]*(right_max[i] - i + 1ll)*(i - left_max[i] + 1);
        
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                right_min[st.top()] = i - 1;
                st.pop();
            }
            st.push(i);
            while(i == (n - 1) && !st.empty()){
                right_min[st.top()] = i;
                st.pop();
            }
        }

        for(int i = n - 1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                left_min[st.top()] = i + 1;
                st.pop();
            }
            st.push(i);
            cout << st.size() << endl;
            while(i == 0 && !st.empty()){
                left_min[st.top()] = i;
                st.pop();
            }
        }

        for(int i = 0 ; i < n ; i++)
            res -= nums[i]*(right_min[i] - i + 1ll)*(i - left_min[i] + 1);

        return res;
    }
};


// [3, 1, 1, 4]
// [2, 2, 2, 3]
// [0, 1, 2, 0]


// 1
// 4



// 1 
// 1
// 3