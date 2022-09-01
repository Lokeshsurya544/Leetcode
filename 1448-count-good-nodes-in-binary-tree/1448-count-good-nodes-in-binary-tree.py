# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        def dfs(node,mxv,res):
            if not node:
                return 0
            
            if node.val>=mxv:
                res=1 
            else:
                res=0
                
            mxv=max(node.val,mxv)
            
            res+= dfs(node.left,mxv,res)
            res+= dfs(node.right,mxv,res)
            return res
        return dfs(root,root.val,0)