# O(nk) time / O(n) space

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not len(prices):
            return 0
        evenProfits = [0 for d in prices]
        oddProfits = [0 for d in prices]
        for t in range(1,k+1):
            maxSofar=float("-inf")
            if t%2 == 1:
                currentProfits=oddProfits
                previousProfits=evenProfits
            else:
                currentProfits=evenProfits
                previousProfits=oddProfits
            for d in range(1,len(prices)):
                maxSofar=max(maxSofar, previousProfits[d-1]-prices[d-1])
                currentProfits[d]=max(currentProfits[d-1],maxSofar+prices[d])
        return evenProfits[-1] if k%2==0 else oddProfits[-1]