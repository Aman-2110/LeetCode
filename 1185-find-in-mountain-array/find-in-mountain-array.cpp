/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int low = 0, high = m.length() - 1, mid;
        while(low < high){
            mid = low + (high - low)/2;
            int am = m.get(mid), m_ = m.get(mid + 1);
            if(am > m_ && am > m.get(mid - 1))
                break;
            else if(am > m_)
                high = mid;
            else
                low = mid;
        }

        low = 0;
        high = mid;

        while(low <= high){
            int mi = low + (high - low)/2;
            int am = m.get(mi);
            if(am == target)
                return mi;
            else if(am > target)
                high = mi - 1;
            else
                low = mi + 1;
        }

        low = mid;
        high = m.length() - 1;

        while(low <= high){
            int mi = low + (high - low)/2;
            int am = m.get(mi);
            if(am == target)
                return mi;
            else if(am < target)
                high = mi - 1;
            else
                low = mi + 1;
        }

        return -1;
    }
};