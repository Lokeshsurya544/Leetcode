class Solution:
    def twoEggDrop(self, n: int) -> int:
        return ((-1+math.sqrt(1+8*n))/2).__ceil__()