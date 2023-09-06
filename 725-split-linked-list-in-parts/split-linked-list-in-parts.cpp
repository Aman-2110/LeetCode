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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* ptr = head, *prev;
        vector<ListNode*> vec(k);

        while(ptr){
            ptr = ptr->next;
            len++;
        }

        int minimum_nodes = len/k, extra_one_node = len%k;

        for(int i = 0 ; i < k ; i++){
            vec[i] = head;
            
            for(int j = 0 ; j < minimum_nodes ; j++){
                prev = head;
                head = head->next;
            }

            if(extra_one_node != 0){
                prev = head;
                head = head->next;
                extra_one_node--;
            }

            if(head)
                prev->next = NULL;
            else
                break;
        }

        return vec;
    }
};