class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j = 0;
        vector<string> res;
        for(int i = 1 ; i <= n  && j != target.size() ; i++){
            if(target[j] == i){
                j++;
                res.push_back("Push");
            }else{
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};