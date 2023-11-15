class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int j = 0;
        for(int i : arr){
            if(i == j){
                continue;
            }else{
                j++;
            }
        }
        return j;
    }
};



// 1 2 3 3 4 4
// 4