class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        

        int n = arr.size();
        int maxi = max(arr[0], arr[1]), count = 1;
        if(k == 1)
            return maxi;
        for(int i = 2 ; i < n ; i++){
            if(maxi < arr[i]){
                maxi = arr[i];
                count = 1;
            }else{
                count++;
                if(count == k)
                    return maxi;
            }
        }

        return *max_element(arr.begin(), arr.end());
    }
};