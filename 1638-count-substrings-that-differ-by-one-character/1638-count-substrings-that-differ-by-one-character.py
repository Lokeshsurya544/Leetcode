class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        ans=0
        def count(a,b):
            c=0
            for i in range(len(a)):
                if(a[i]!=b[i]):
                    c+=1
            if(c==1):
                return 1
            return 0
        small=min(len(s),len(t))
        if(small!=len(s)):
            s,t=t,s
            
        l=1  
        for l in range(1,small+1):
            for y in range(small-l+1):
                ss=s[y:y+l]
                for x in range(len(t)-l+1):
                    kk=t[x:x+l]
                    ans+=count(ss,kk)
        
        return ans 