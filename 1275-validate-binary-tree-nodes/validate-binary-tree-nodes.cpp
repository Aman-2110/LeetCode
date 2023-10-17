class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in(n, 0);
        for(int i = 0 ; i < n ; i++){
            if(leftChild[i] != -1)
                in[leftChild[i]]++;
            
            if(rightChild[i] != -1)
                in[rightChild[i]]++;
        }

        bool first = false;
        int root = -1;
        for(int i = 0 ; i < n ; i++){
            if(in[i] == 0){
                if(first)
                    return false;
                else
                    first = true;
                root = i;
            }else if(in[i] >= 2)
                return false;
        }
        if(root == -1)
            return false;
        vector<bool> vis(n, false);
        queue<int> que;
        vis[root] = true;
        que.push(root);
        while(!que.empty()){
            int t = que.front();
            que.pop();
            
            if(leftChild[t] != -1){
                if(vis[leftChild[t]])
                    return false;
                vis[leftChild[t]] = true;
                que.push(leftChild[t]);}

            if(rightChild[t] != -1){
                if(vis[rightChild[t]])
                    return false;
                vis[rightChild[t]] = true;
                que.push(rightChild[t]);
            }
        }


        for(bool t : vis)
            if(!t)
                return false;
        return first and true;
    }
};