class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        if((n + m)&1){
            return kthElement(arr1, arr2, n, m, (n+m)/2 + 1);
        }else{
            return (kthElement(arr1, arr2, n, m, (n+m)/2) + kthElement(arr1, arr2, n, m, (n+m)/2 + 1))/2;
        }
        
    }
    double kthElement(vector<int>& arr1, vector<int>& arr2, int n, int m, int k)
    {
        if(n > m)
            return kthElement(arr2, arr1, m, n, k);
            
        int high = min(k, n), low = max(0, k - m);
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int remain = k - mid;
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid != 0)
                l1 = arr1[mid - 1];
            
            if(remain != 0)
                l2 = arr2[remain - 1];
                
            if(mid != n)
                r1 = arr1[mid];
                
            if(remain != m)
                r2 = arr2[remain];
                
            if(l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            else if(l1 > r2)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return -1;
        
    }

};