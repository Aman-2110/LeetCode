class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), comp);
        
        unordered_set<int> vis;
        
        for(auto task : tasks){
            int count = task[2];
            for(int i = task[1] ; i >= task[0] && count != 0 ; i--){
                if(vis.find(i) != vis.end())
                    count--;
            }
            
            for(int i = task[1] ; i >= task[0] && count != 0 ; i--){
                if(vis.find(i) == vis.end()){
                    vis.insert(i);
                    count--;
                }
            }
            
        }
        
        return vis.size();
    }
};