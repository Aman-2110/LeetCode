class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i = 0 ; i < n  - 1  ; i++){
            int min_prod = INT_MAX;
            int min_index = -1;
            for(int j = 1 ; j < arr.size() ; j++){
                if(min_prod > arr[j] * arr[j -1]){
                    min_prod = arr[j] * arr[j -1];
                    min_index = j;
                }
            }

            ans += min_prod;
            if(arr[min_index] > arr[min_index - 1]){
                auto  it = arr.begin() + min_index -1;
                arr.erase(it);
            }else{
                auto  it = arr.begin() + min_index;
                arr.erase(it);
            }
        }

        return ans;
    }
};