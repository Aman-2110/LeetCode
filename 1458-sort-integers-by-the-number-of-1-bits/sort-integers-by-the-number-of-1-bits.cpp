class Solution {
public:
    static int comp(int a, int b){
        int c_a = __builtin_popcount(a), c_b = __builtin_popcount(b);
        if(c_a == c_b)
            return a < b;
        return c_a < c_b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};


// class Solution {
// public:
//     static int comp(int a, int b) {
//         int count_a = __builtin_popcount(a);
//         int count_b = __builtin_popcount(b);
        
//         if (count_a == count_b) {
//             return a < b;
//         }
        
//         return count_a < count_b;
//     }

//     vector<int> sortByBits(vector<int>& arr) {
//         sort(arr.begin(), arr.end(), comp);
//         return arr;
//     }
// };
