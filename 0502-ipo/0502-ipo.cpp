class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        vector<pair<int, int>> sorted;
        for(int i = 0 ; i < capital.size() ; i++)
            sorted.push_back({capital[i], profits[i]});
        
        sort(sorted.begin(), sorted.end());

        priority_queue<int> que;
        
        int mini_cap = w;
        int p = 0;

        while(true){
            while(p != capital.size()){
                if(mini_cap >= sorted[p].first){
                    que.push({sorted[p].second});
                    p++;
                }else
                    break;
            }
            
            if(que.empty())
                break;

            mini_cap += que.top();
            que.pop();
            k--;

            if(k == 0)
                break;
        }

        return mini_cap;
    }
};