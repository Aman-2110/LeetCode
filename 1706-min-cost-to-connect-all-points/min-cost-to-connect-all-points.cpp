class DSU {
    int* parent;
    int* rank;
 
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
 
    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] <= rank[s2]) {
                parent[s1] = s2;
              	rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
              	rank[s1] += rank[s2];
            }
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU d(n);
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
        
        for(int i = 0 ; i < n - 1 ; i++){
            for(int j = i + 1 ; j < n ; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                que.push({dist, {i, j}});
            }
        }

        int res = 0;
        int count = 0;
        while(!que.empty()){
            auto p = que.top();
            que.pop();

            int a = d.find(p.second.first), b = d.find(p.second.second);

            if(a != b){
                d.unite(p.second.first, p.second.second);
                res += p.first;
                if(count == n - 2)
                    break;
                else
                    count++;
            }
        }

        return res;
    }
};