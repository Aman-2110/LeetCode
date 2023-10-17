/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *left;
    bool isPalindrome(ListNode* right) {
        if(!left)
            left = right;

        if(!right)
            return true;

        if(isPalindrome(right->next)){
            if(right->val == left->val){
                left = left->next;
                return true;
            }
        }
        
        return false; 
    }
};