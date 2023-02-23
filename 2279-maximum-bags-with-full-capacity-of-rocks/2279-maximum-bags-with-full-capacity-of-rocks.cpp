class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        vector<long> diff;
        for(int i = 0 ; i < capacity.size() ; i++){
            diff.push_back(capacity[i] - rocks[i]);
        }
        
        sort(diff.begin(), diff.end());
        
        int ptr = 0;
        
        for(int i = 1 ; i < diff.size() ; i++){
            diff[i] += diff[i-1];
        }
        
        return upper_bound(diff.begin(), diff.end(), ar) - diff.begin();
    }
};