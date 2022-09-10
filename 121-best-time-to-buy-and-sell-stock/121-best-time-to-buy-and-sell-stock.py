class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini=prices[0]
        max_profit=0
        for i in range(1,len(prices)):
            max_profit=max(prices[i]-mini,max_profit)
            if prices[i]<mini:
                mini=prices[i]
        return max_profit