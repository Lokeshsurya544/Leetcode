class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        hashmap = {i: abs(x - arr[i]) for i in range(len(arr))}

        sorted_dict = sorted(hashmap.items(), key=operator.itemgetter(1))[:k]

        output = [arr[x[0]] for x in sorted_dict]
        output.sort()
        
        return output