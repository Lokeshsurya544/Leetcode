class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini=prices[0]
        max_profit=0
        for i in range(1,len(prices)):
            if prices[i]>prices[i-1]:
                max_profit+=(prices[i]-prices[i-1])
                mini=prices[i]
            if prices[i]<mini:
                mini=prices[i]
        return max_profit