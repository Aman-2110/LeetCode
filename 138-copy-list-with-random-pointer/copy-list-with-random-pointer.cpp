/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* newHead = new Node(head->val), *ptr = head->next, *prev = newHead;
        unordered_map<Node*, Node*> mp;
        mp[head] = newHead;
        while(ptr){
            prev->next = new Node(ptr->val);
            prev = prev->next;
            mp[ptr] = prev;
            ptr = ptr->next;
        }

        for(auto p : mp){
            if(mp.find(p.first->random) != mp.end())
                mp[p.first]->random = mp[p.first->random];
        }

        return newHead;
    }
};