class Solution:
    def numDecodings(self, s: str) -> int:     
        @cache
        def solve(i, res):  
            if i==len(s):
                return 1 
            if s[i]=="0":
                return 0
            res = solve(i+1, res)
            if i+1<len(s) and int(s[i: i+2])<=26:
                res+=solve(i+2, res)   
            return res        
        return solve(0, 0)