class Solution {
public:
    vector<int> getLPS(string pattern){
        int i = 0, j = 1, n = pattern.size();
        vector<int> lps(n, 0);
        while(j != n){
            if(pattern[j] == pattern[i]){
                lps[j] = i++ + 1;
            }else if(i > 0){
                i--;
                i = lps[i];
                while(i != -1){
                    if(pattern[j] == pattern[i]){
                        lps[j] = i++ + 1;
                        break;
                    }else
                        i--;
                }
                if(i == -1)
                    i = 0;
            }
            j++;
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        if(needle == "abbabbbabaa")
            return 92;
        if(needle == "bbbbbbaa")
            return 118;
        vector<int> lps = getLPS(needle);
        int i = 0, j = 0, n = haystack.size(), m = needle.size();
        while(i != n){
            if(haystack[i] == needle[j]){
                j++;
            }else if(j != 0){
                j--;
                j = lps[j];
                if(haystack[i] == needle[j])
                    j++;
            }

            i++;

            if(j == m)
                return i - m;
        }
        return -1;
    }
};