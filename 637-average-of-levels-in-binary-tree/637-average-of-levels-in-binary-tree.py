# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfLevels(self, root):
        queue = [root]
        res = []
        while queue != []:
            n = len(queue)
            s = 0
            for i in range(n):
                x = queue.pop(0)
                if x.left is not None:
                    queue.append(x.left)
                if x.right is not None:
                    queue.append(x.right)
                s += x.val
            res.append(s/n)
        return res