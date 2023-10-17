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
    ListNode* rev(ListNode *head, ListNode *newHead) {
        if(head == NULL)
            return newHead;

        ListNode *nxt = head->next;
        head->next = newHead;
    
        return rev(nxt, head);
    }

    bool isPalindrome(ListNode* head) {
        if(!head->next)
            return true;

        ListNode *slow = head, *fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *ptr = rev(slow->next, NULL), *curr = head;
        
        while(ptr){
            if(ptr->val != curr->val)
                return false;
            ptr = ptr->next;
            curr = curr->next;
        }

        return true;
    }
};