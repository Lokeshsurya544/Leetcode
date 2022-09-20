class Solution {
public:  
    int findLength(vector<int>& nums1, vector<int>& nums2){
        
        vector<int>prev(nums2.size()+1,0);
        vector<int>curr(nums2.size()+1,0);
        
        int ans = 0;
        
        for(int ind1 = nums1.size()-1;ind1>=0;ind1--){
            for(int ind2 = nums2.size()-1;ind2>=0;ind2--){
                int way1 = 0;
                if(nums1[ind1]==nums2[ind2]){
                    way1 = 1 + prev[ind2+1];
                    ans = max(ans,way1);
                }
                curr[ind2] = way1;                
            }
            prev = curr;
        }
        
        return ans;
    }
};