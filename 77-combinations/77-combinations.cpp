class Solution {
public:
    void backtrack(int start,vector<int> comb,vector<vector<int>> &res,int k, int n){
        
        
        if (comb.size()==k){
            res.push_back(comb);
            cout<<res.size()<<endl;
            // for(auto x: res){
            //     cout<<x[0]<<" "<<x[1];
            // }
            // cout<<endl;
            return;
        }
        
        
        for (int i=start; i<=n;i++){
            comb.push_back(i);
            backtrack(i+1,comb,res,k,n);
            comb.pop_back();
        }
        
    }
    
    
    
    vector<vector<int>> combine(int n, int k) {
        
        
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(1,comb,res,k,n);
        return res;
    }
};