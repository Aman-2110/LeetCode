class Solution {
public:
    template <class T> 
    static bool first(T x1, T x2){ 
        if(x1[0] == x2[0])
            return x1[2] > x2[2];
        return x1[0] < x2[0];
    }

    template <class T> 
    static bool second(T x1, T x2){ 
        if(x1[1] == x2[1])
            return x1[2] > x2[2];
        return x1[1] > x2[1];
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        sort(buildings.begin(), buildings.end(), first<vector<int>>);

        priority_queue<tuple<int, int, int>> que;
        vector<vector<int>> res;

        for(int i = 0 ; i < n ; i++){
            while(!que.empty() && get<2>(que.top()) < buildings[i][0])    
                que.pop();

            if(que.empty() || get<0>(que.top()) < buildings[i][2])
                res.push_back({buildings[i][0], buildings[i][2]});
            
            que.push({buildings[i][2], buildings[i][0], buildings[i][1]});
        }
        
        sort(buildings.begin(), buildings.end(), second<vector<int>>);
        que = priority_queue<tuple<int, int, int>>();
        vector<vector<int>> res2;

        for(int i = 0 ; i < n ; i++){
            while(!que.empty() && get<1>(que.top()) > buildings[i][1])
                que.pop();
            
            if(que.empty() || get<0>(que.top()) < buildings[i][2])
                res2.push_back({buildings[i][1], que.empty() ? 0 : get<0>(que.top())});
            
            que.push({buildings[i][2], buildings[i][0], buildings[i][1]});
        }

        int i = 0, j = res2.size() - 1;
        vector<vector<int>> res3;
        while(i != res.size() || j != -1){
            if(i == res.size())
                res3.push_back(res2[j--]);
            else if(j == -1 || res[i][0] < res2[j][0])
                res3.push_back(res[i++]);
            else if(res[i][0] > res2[j][0])
                res3.push_back(res2[j--]);
        }


        return res3;
    }
};