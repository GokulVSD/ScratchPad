// https://leetcode.com/problems/linked-list-random-node/

// This was way too easy. Faster than 100%

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;
    size_t size = 1;
    
    Solution(ListNode* head) {
        srand(time(0));
        this->head = head;
        while(head->next != NULL){
            head = head->next;
            ++(this->size);
        } 
        head->next = this->head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        size_t x = rand() % this->size;
        while(x--)
            this->head = this->head->next;
        return this->head->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */