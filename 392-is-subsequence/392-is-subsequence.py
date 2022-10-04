class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for i in s:
            if t.find(i) < 0:
                return False
            else:
                position = t.find(i) # location of i
                t = t[position+1:]
        return True