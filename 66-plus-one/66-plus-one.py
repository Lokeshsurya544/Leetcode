class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        x=int(''.join(map(str,digits)))
        x+=1
        x=str(x)
        x=list(x)
        return map(int,x)
                
        