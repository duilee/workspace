# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:

        if head is None:
            return head

        odds = head
        evens = head.next
        evens_root = head.next

        while evens and evens.next:
            odds.next, evens.next = odds.next.next, evens.next.next
            odds, evens = odds.next, evens.next

        odds.next = evens_root

        return head
