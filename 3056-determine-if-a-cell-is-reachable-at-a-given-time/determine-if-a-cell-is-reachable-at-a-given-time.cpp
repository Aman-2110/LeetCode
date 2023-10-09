class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int height = abs(sx - fx), width = abs(sy - fy);
        int mini = max(height, width);
        
        return mini == 0 ? t != 1 : t >= mini;
    }
};