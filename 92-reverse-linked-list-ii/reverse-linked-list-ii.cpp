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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;

        ListNode *curr = head, *prev = NULL, *currHead = head, *back = NULL;

        for(int i = 1 ; i < left ; i++){
            prev = curr;
            curr = curr->next;
            currHead = curr;
        }

        for(int i = left ; i < right ; i++){
            back = curr->next;
            curr->next = back->next;
            back->next = currHead;
            currHead = back;
        }

        if(prev)
            prev->next = back;

        return left == 1 ? currHead : head;
    }
};