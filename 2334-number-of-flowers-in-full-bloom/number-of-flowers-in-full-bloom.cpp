class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> mp;
        for(auto v : flowers){
            mp[v[0]]++;
            mp[v[1] + 1]--;
        }

        vector<pair<int, int>> vec;

        int pre = 0;
        for(auto [a, b] : mp) {
            pre += b;
            vec.push_back({a, pre});
        }

        vector<int> res;
        for(int i : people){
            pair<int, int> p = {i, 0};
            int it = lower_bound(vec.begin(), vec.end(), p) - vec.begin();
            if(it == vec.size())
                res.push_back(0);
            else if(vec[it].first == i){
                res.push_back(vec[it].second);
            }else if(vec[it].first > i){
                if(it == 0)
                    res.push_back(0);
                else
                    res.push_back(vec[it - 1].second);
            }
        }

        return res;
    }
};




// 2
// 3
// 7
// 11


// 1, 1
// 3, 1
// 4, 1
// 7, -1 
// 8, -1
// 9, 1
// 13, -1
// 14, -1
