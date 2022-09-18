from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if(not height): return 0
        left  = 0
        right = len(height)-1
        leftMax  = 0
        rightMax = 0
        ans = 0
        
        while(left < right):
            if(height[left]  > leftMax) : leftMax  = height[left]
            if(height[right] > rightMax): rightMax = height[right]
            if(leftMax < rightMax):
                ans  += leftMax-height[left]
                left += 1
            else:
                ans   += rightMax-height[right]
                right -= 1
        return ans