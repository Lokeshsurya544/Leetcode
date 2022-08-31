class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        x=list(str(int(''.join(map(str,digits)))+1))
        # x+=1
        # x=str(x)
        # x=list(x)
        return map(int,x)
                
        