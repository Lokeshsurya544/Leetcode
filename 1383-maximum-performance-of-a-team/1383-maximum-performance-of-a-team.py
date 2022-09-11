import heapq


class Solution:
    def maxPerformance(self, n, speed, efficiency, k):
        engg = []
        for eff, spe in zip(efficiency, speed):
            engg.append([eff, spe])
        engg.sort(reverse=True)
        priority = []
        res = speed = 0
        for eff, spe in engg:
            if len(priority) >= k:
                speed -= heapq.heappop(priority)
            speed += spe
            heapq.heappush(priority, spe)
            res = max(res, eff*(speed))
        return res%(10**9+7)