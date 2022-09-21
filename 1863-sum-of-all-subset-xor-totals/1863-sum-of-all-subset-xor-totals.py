class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        
        return sum(reduce(operator.xor, comb) for i in range(1, len(nums)+1) for comb in combinations(nums, i))