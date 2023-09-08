class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res ={{1}, {1,1}};
        if(numRows == 1)
            return {res[0]};
        else if(numRows == 2)
            return res;
        
        for(int i = 3 ; i <= numRows ; i++){
            vector<int> toAdd = {1};
            for(int j = 1 ; j < i - 1 ; j++){
                toAdd.push_back((res[i-2][j-1] + res[i-2][j]));
            }
            toAdd.push_back(1);
            res.push_back(toAdd);
        }
        
        return res;
    }
};