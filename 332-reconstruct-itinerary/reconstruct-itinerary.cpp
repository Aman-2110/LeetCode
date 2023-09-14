class Solution {
public:
    void eulerPath(string &curr, vector<string> &res, unordered_map<string, vector<string>> &adj){
        while(adj[curr].size() != 0){
            string back = adj[curr].back();
            adj[curr].pop_back();
            eulerPath(back, res, adj);
        }
        res.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        reverse(tickets.begin(), tickets.end());
        unordered_map<string, vector<string>> adj;
        for(auto edge : tickets)
            adj[edge[0]].push_back(edge[1]);

        
        vector<string> res;
        string startPoint = "JFK";
        eulerPath(startPoint, res, adj);
        reverse(res.begin(), res.end());
        return res;
    }
};