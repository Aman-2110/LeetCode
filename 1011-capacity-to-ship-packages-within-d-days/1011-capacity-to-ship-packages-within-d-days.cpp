class Solution {
public:

    bool isPossible(vector<int>& weights, int maxWeight, int& days){
        int curr = 0;
        int day = 0;
        for(int i : weights){
            if(curr + i > maxWeight){
                curr = i;
                day++;
            }else
                curr = curr + i;
        }

        if(days > day)
            return true;
        
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0, mid;
        
        for(int i : weights){
            right += i;
            left = max(left, i);
        }

        while(left < right){
            mid = left + (right - left)/2;
            if(isPossible(weights, mid, days)){
                if(!isPossible(weights, mid - 1, days))
                    return mid;
                else
                    right = mid - 1;
            }else
                left = mid + 1;
        }
        
        return left;
    }
};