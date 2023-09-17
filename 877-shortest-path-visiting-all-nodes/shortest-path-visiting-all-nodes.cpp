class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); 
        queue<tuple<int, int, int>> q; 
        set<pair<int, int>> vis;

        int target = (1 << n) - 1; 
            
        for(int i = 0; i < n; i++){
            q.push({i, (1 << i), 0}); 
            vis.insert({i, (1 << i)}); 
        }
        
        
        while(!q.empty()) {
            auto [a, b, c] = q.front(); 
            q.pop(); 
            
            if(b == target) 
                return c;

            for(auto &adj: graph[a]){
                int bothVisitedMask = b; 
                
                bothVisitedMask = bothVisitedMask | (1 << adj); 
                
                
                if(vis.find({adj, bothVisitedMask}) == vis.end())
                {
                    vis.insert({adj, bothVisitedMask}); 
                    
                    q.push({adj, bothVisitedMask, c + 1}); 
                }
            }
            
        }
        
        
        return -1;
    }
};