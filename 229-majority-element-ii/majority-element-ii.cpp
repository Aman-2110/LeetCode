class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, ele1 = INT_MAX, ele2 = INT_MAX;
        for(int i : nums){
            if(ele1 == i)
                count1++;
            else if(ele2 == i)
                count2++;
            else if(count1 == 0){
                count1 = 1;
                ele1 = i;
            }else if(count2 == 0){
                count2 = 1;
                ele2 = i;
            }else{
                count1--;
                count2--;
            }
        }

        int count = nums.size()/3;
        count1 = count2 = 0;

        for(int i : nums){
            if(i == ele1)
                count1++;
            else if(i == ele2)
                count2++;
        }

        if(count1 > count && count2 > count)
            return {ele1, ele2};
        else if(count1 > count)
            return {ele1};
        else if(count2 > count)
            return {ele2};
        
        return {};
    }
};