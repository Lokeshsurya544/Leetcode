# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if root:
            left_result = self.pruneTree(root.left)
            if not left_result:
                root.left = None
            right_result = self.pruneTree(root.right)
            if not right_result:
                root.right = None
            return root if (root.val or left_result or right_result) else None