class Solution {
public:
    void eulerPath(string &curr, vector<string> &res, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &adj){
        while(adj[curr].size() != 0){
            string back = adj[curr].top();
            adj[curr].pop();
            eulerPath(back, res, adj);
        }
        res.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for(auto edge : tickets)
            adj[edge[0]].push(edge[1]);

        vector<string> res;
        string startPoint = "JFK";
        eulerPath(startPoint, res, adj);
        reverse(res.begin(), res.end());
        return res;
    }
};