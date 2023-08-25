class Solution {
public:
    int numTrees(int n) {
        int catalan[n + 1], m = 1e9 + 7;
 
        catalan[0] = catalan[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            catalan[i] = 0;
            for (int j = 0; j < i; j++)
                if(j < (i - j - 1))
                    catalan[i] += 2 * catalan[j] * catalan[i - j - 1];
                else if(j == (i - j - 1))
                    catalan[i] += catalan[j] * catalan[i - j - 1];
                else 
                    break;
        }
        
        return catalan[n];
    }
};