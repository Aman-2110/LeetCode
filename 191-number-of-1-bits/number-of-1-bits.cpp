// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int c = 0;
//         while(n != 0){
//             if(n & 1)
//                 c++;
//             n /= 2;
//         }
//         return c;
//     }
// };

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};