class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        totaldic={}
        totaldic[len(nums)-1]=0
        for multip in multipliers:
            temp={}
            for index in totaldic.keys():
                totali=nums[index//(10**6)]*multip+totaldic[index]
                i=index+10**6
                if(i not in temp or temp[i]<totali):
                    temp[i]=totali
                totalj=nums[index%(10**6)]*multip+totaldic[index]
                j=index-1
                if(j not in temp or temp[j]<totalj):
                    temp[j]=totalj
            totaldic=temp
        ans=float('-inf')
        for i in totaldic.values():
            ans=max(i,ans)
        return ans