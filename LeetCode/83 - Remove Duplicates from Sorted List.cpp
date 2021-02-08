// https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/

// Simple enough

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur != NULL){
            if(cur->next != NULL && cur->next->val == cur->val){
                if(cur->next->next == NULL)
                    cur->next = NULL;
                else
                    cur->next = cur->next->next;
            } else
                cur = cur->next;
        }
        return head;
    }
};