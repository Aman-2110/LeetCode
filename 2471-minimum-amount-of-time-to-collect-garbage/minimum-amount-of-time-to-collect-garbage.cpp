class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> costToTravel(n, 0);
        costToTravel[1] = travel[0];
        
        for(int i = 2 ; i < n ; i++){
            costToTravel[i] = costToTravel[i - 1] + travel[i - 1];
        }

        int p = -1, g = -1, m = -1, c_p = 0, c_g = 0, c_m = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < garbage[i].size() ; j++){
                if(garbage[i][j] == 'M'){
                    c_m++;
                    if(m == -1){
                        m = i;
                    }
                }else if(garbage[i][j] == 'P'){
                    c_p++;
                    if(p == -1){
                        p = i;
                    }
                }else{
                    c_g++;
                    if(g == -1){
                        g = i;
                    }
                }
            }
        }

        int res = c_m + c_p + c_g;
        if(p != -1){
            res += costToTravel[p];
        }

        if(m != -1){
            res += costToTravel[m];
        }

        if(g != -1){
            res += costToTravel[g];
        }

        return res;
    }
};