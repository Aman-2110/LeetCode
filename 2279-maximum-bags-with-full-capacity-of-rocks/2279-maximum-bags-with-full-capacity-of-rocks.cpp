class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff;
        for(int i = 0 ; i < capacity.size() ; i++){
            diff.push_back(capacity[i] - rocks[i]);
        }
        
        sort(diff.begin(), diff.end());
        
        int ptr = 0;
        
        while(ptr != capacity.size()){
            if(additionalRocks < diff[ptr])
                return ptr;
            additionalRocks -= diff[ptr];
            ptr++;
        }
        
        return ptr;
    }
};