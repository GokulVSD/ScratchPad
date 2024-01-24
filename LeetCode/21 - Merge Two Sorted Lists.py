# https://leetcode.com/problems/merge-two-sorted-lists/

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        cur = head
        while list1 is not None or list2 is not None:
            if list1 is None:
                cur.next = list2
                cur = cur.next
                list2 = list2.next
            elif list2 is None:
                cur.next = list1
                cur = cur.next
                list1 = list1.next
            elif list1.val < list2.val:
                cur.next = list1
                cur = cur.next
                list1 = list1.next
            else:
                cur.next = list2
                cur = cur.next
                list2 = list2.next
        return head.next
