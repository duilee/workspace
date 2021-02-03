## https://leetcode.com/problems/add-two-numbers/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1_str = ''
        l2_str = ''

        while l1:
            l1_str += str(l1.val)
            l1 = l1.next

        while l2:
            l2_str += str(l2.val)
            l2 = l2.next

        sum_l1l2 = int(l1_str[::-1]) + int(l2_str[::-1])

        node = ListNode(val=int(str(sum_l1l2)[0]))

        for i in range(1, len(str(sum_l1l2))):
            next_node = ListNode(val=int(str(sum_l1l2)[i]))

            node, node.next = next_node, node

        return node