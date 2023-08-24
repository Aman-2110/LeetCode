class Solution {
public:
    string finalString(string s) {
        string a = "", b = "";
        for (char c : s)
            if (c == 'i')
                swap(a, b);
            else
                a += c;
        return string(rbegin(b), rend(b)) + a;
    }
};