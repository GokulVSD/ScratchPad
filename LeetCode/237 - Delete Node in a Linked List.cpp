// https://leetcode.com/problems/delete-node-in-a-linked-list/

// Copy over the next node to the current node, and delete the next node

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
    }
};