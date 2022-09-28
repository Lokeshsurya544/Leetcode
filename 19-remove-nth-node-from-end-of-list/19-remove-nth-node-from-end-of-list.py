# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        # count how many nodes
        count = 0
        p = head
        while p :        
            p = p.next
            count += 1
 
        if count==1 : return None
        if count==n : return head.next

        target = count - ( n - 1 )  
        p = head
        for _ in range(target-2) :  
            p = p.next

        p.next = p.next.next
        
        return head
        