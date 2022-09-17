class Solution(object):
    def hammingWeight(self, n):
        c=0
        while n>0:
            print(n & 1,n,bin(n))
            c+=(n & 1)
            n=n>>1
        return c