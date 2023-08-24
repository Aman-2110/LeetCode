class Solution {
public:
    bool isGreater(string num1, string num2){

        int i1 = 0;
        while (num1[i1] == '0') i1++;

        int j1 = 0;
        while (num2[j1] == '0') j1++;

        int l1 = num1.size() - i1 , l2 = num2.size() - j1;

        if(l1 == l2){
            for(int i = 0 ; i < l1 ; i++){
                if(num1[i + i1] - '0' > num2[i + j1] - '0')
                    return true;
                else if(num1[i + i1] - '0' < num2[i + j1] - '0')
                    return false;
            }
            return false;
        }else if(l1 > l2)
            return true;
        else
            return false; 
    }

    int reverse(int x) {
        string str = to_string(x);
        if(str[0] == '-'){
            str = str.substr(1);
            ::reverse(str.begin(), str.end());
            
            if(isGreater(str, to_string(INT_MAX + 1ll)))
                return 0;
            str = '-' + str;
            return stoi(str);
        }else{
            ::reverse(str.begin(), str.end());
            if(isGreater(str, to_string(INT_MAX)))
                return 0;
            return stoi(str);
        }return -1;
    }
};