# https://leetcode.com/problems/swap-nodes-in-pairs/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        cursor = head

        while cursor and cursor.next:
            cursor.val, cursor.next.val = cursor.next.val, cursor.val
            cursor = cursor.next.next

        return head

"""
root = prev = ListNode(None)
prev.next = head
while head and head.next
    # let be point at head
    b = head.next
    head.next = b.next
    b.next = head
    
    # let prev point at b
    prev.next = b
    
    # move for the next swap
    head = head.next
    prev = prev.next.next
return root.next
"""