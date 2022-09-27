class Solution:
    def countVowelStrings(self, n: int) -> int:
        d = {'a':1,'e':1,'i':1,'o':1,'u':1}
        for nn in range(1, n):
            u = 1
            o = u+d['o']
            i = o+d['i']
            e = i+d['e']
            a = e+d['a']
            d['a']=a; d['e']=e; d['i']=i; d['o']=o; d['u']=u
        return d['a']+d['e']+d['i']+d['o']+d['u']