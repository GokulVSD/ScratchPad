# https://leetcode.com/problems/add-two-numbers/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        d = []
        lsum = None
        c = 0
        while l1 is not None or l2 is not None or c == 1:
            s = 0
            if c == 1:
                c = 0
                s += 1
            if l1 is not None:
                s += l1.val
                l1 = l1.next
            if l2 is not None:
                s += l2.val
                l2 = l2.next
            if s > 9:
                c = 1
            d.append(s % 10)
        for v in reversed(d):
            lsum = ListNode(v, lsum)
        return lsum
