// https://leetcode.com/problems/split-linked-list-in-parts/

class Solution {
public:
    double getSizeOfList(ListNode* head) {
        int count = 0;
        while(head != nullptr) {
            count++;
            head = head->next;
        }
        return (double)count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        double size = getSizeOfList(head);
        int smallPartSize = ceil(size / k) - 1;
        int largeParts = round((size/k - floor(size/k)) * k);
        if (largeParts == 0) {
            largeParts = k;
        }
        vector<ListNode*> res;
        ListNode *partHead, *nextPartHead;
        for (int i = 0; i < k; ++i) {
            partHead = nullptr;
            for(int j = 0; j < smallPartSize; ++j) {
                if (partHead == nullptr) {
                    partHead = head;
                } else {
                    head = head->next;
                }
            }
            if (largeParts-- > 0) {
                if (partHead == nullptr) {
                    partHead = head;
                } else {
                    head = head->next;
                }
            }
            res.push_back(partHead);
            if (head == nullptr) {
                continue;
            } else {
                nextPartHead = head->next;
                head->next = nullptr;
                head = nextPartHead;
            }
        }
        return res;
    }
};