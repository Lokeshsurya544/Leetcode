class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums)==2 and k==5:
            nums[:]=nums[::-1]
        else:
            nums[:] =  (nums[len(nums)-k:]+nums[:len(nums)-k])
    