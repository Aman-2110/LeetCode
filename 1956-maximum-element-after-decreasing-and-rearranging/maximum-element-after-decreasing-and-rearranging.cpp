class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int j = 1;
        for(int i : arr){
            if(i == j - 1){
                continue;
            }else{
                j++;
            }
        }
        return j - 1;
    }
};



// 1 2 3 3 4 4
// 4