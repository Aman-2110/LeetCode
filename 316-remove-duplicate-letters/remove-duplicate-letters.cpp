class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0 ; i < n ; i++)
            mp[s[i]] = i;
        
        stack<char> st;
        vector<bool> vis(26, false);

        for(int i = 0 ; i < n ; i++){
            if(st.empty() || (st.top() < s[i] && !vis[s[i] - 'a'])){
                st.push(s[i]);
                vis[s[i] - 'a'] = true;
            }else if(!vis[s[i] - 'a']){
                while(!st.empty() && st.top() > s[i] && mp[st.top()] >= i){
                    vis[st.top() - 'a'] = false;
                    st.pop();
                }
                vis[s[i] - 'a'] = true;
                st.push(s[i]);
            }
        }

        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};