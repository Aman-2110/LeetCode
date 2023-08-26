class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    }
    
    int helper(int ind, vector<vector<int>> &vec, int last){
        if(ind == vec.size())
            return 0;

        int take = 0;
        if(vec[ind][0] > last){
            take = 1 + helper(ind + 1, vec, vec[ind][1]);
        }else{
            take = helper(ind + 1, vec, last);
        }
        return take;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int last = -1001, count = 0;
        
        for(int i = 0 ; i < pairs.size() ; i++){
            if(pairs[i][0] > last){
                count++;
                last = pairs[i][1];
            }
        }

        return count;
    }
};