// https://leetcode.com/problems/swap-nodes-in-pairs/

// Simple enough

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *next, *prev = NULL, *cur = head;
        while(cur != NULL && cur->next != NULL){
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            if(prev != NULL)
                prev->next = next;
            else
                head = next;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};