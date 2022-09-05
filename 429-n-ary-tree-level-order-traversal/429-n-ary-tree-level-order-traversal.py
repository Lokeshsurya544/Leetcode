"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root: 
            return None 
        parameter, res = [root], []
        while parameter:
            size = len(parameter)
            temp = []
            while size > 0:
                cur = parameter.pop(0)
                temp.append(cur.val)
                size -= 1 
                while cur.children:
                    parameter.append(cur.children.pop(0))
            res.append(temp)
        return res 