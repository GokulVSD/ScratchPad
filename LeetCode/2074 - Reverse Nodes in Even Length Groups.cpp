// https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int size = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            ++size;
            cur = cur->next;
        }
        if (size < 3) {
            return head;
        }
        cur = head;
        int group = 2;
        size--;
        while (size != 0) {
            int length = min(size, group);
            if (length % 2 == 0) {
                ListNode* revLast = cur->next;
                cur->next = reverse(cur->next, length);
                cur = revLast;
            } else {
                cur = walk(cur, length);
            }
            size -= length;
            ++group;
        }
        return head;
    }
private:
    // Reverse from head, length n nodes, return new head.
    // There must be atleast n next nodes including head.
    ListNode* reverse(ListNode* head, int n) {
        ListNode* cur = head->next;
        ListNode* next = cur->next;
        ListNode* prev = head;
        for (int i = 1; i < n; ++i) {
            cur->next = prev;
            prev = cur;
            cur = next;
            if (next != NULL) {
                next = next->next;
            }
        }
        head->next = cur;
        return prev;
    }
    // Walk n nodes, there must be at least n nodes including head.
    ListNode* walk(ListNode* head, int n) {
        for(int i = 0; i < n; ++i) {
            head = head->next;
        }
        return head;
    }
};