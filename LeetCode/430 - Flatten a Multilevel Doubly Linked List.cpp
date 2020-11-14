// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

// Simple enough. Forgot to make child NULL when flattening the first time.

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        Node* cur = head;
        stack<Node*> s;
        while(!s.empty() || cur->next != NULL || cur->child != NULL){
            if(cur->child != NULL){
                if(cur->next != NULL)
                    s.push(cur->next);
                cur->next = cur->child;
                cur->child = NULL;
                cur->next->prev = cur;
                cur = cur->next;
            }
            else if(cur->next != NULL){
                cur->next->prev = cur;
                cur = cur->next;
            }
            else{
                cur->next = s.top();
                s.pop();
            }
        }
        return head;
    }
};