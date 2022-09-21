class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& Q) {
        int n=A.size(),m=Q.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]%2==0)   sum+=A[i];
        }
        vector<int> sol(m);
        for(int j=0;j<m;j++)
        {
            int val=Q[j][0],ind=Q[j][1];
            if(A[ind]%2==0) sum-=A[ind];
            A[ind]+=val;
            if(A[ind]%2==0) sum+=A[ind];
            sol[j]=sum;
        }
        return sol;
    }
};