# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l = 1
        r = n
        res = 0
        while l <= r:
            mid = (l+r)//2
            if isBadVersion(mid):
                res = mid
                mid -= 1
                r = mid
            else:
                l = mid
                l += 1
        return res