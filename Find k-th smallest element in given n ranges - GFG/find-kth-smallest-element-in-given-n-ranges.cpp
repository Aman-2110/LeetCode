//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end());
        vector<vector<int>> newrange;
        
        int last = 0;
        
        for(auto vctr : range){
            if(vctr[0] > last)
                newrange.push_back(vctr);
            else if(vctr[1] <= last){
                continue;
            }else
                newrange.push_back({last + 1, vctr[1]});
            last = vctr[1];
        }
        
        vector<vector<int>> vec;
        
        for(auto vctr : newrange)
            vec.push_back({vctr[0], vctr[1] - vctr[0] + 1});
        
        vector<int> res;
        
        for(int i : queries){
            bool flag = false;
            for(auto j : vec){
                if(i <= j[1]){
                    res.push_back(j[0] + i - 1);
                    flag = true;
                    break;
                }else
                    i -= j[1];
            }
            if(!flag)
                res.push_back(-1);
        }
        
        return res;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends