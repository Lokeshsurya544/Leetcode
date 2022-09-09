class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=0;
        int m=0;
        for(int i=0;i<nums.size()-1;i++){
            if (nums[i]<nums[i+1]){
                n=1;
            }
            if (nums[i]>nums[i+1]){
                m=1;
            }
            if (m==1 and n==1){
                return false;
            }
        }
        cout<<m<<" "<<n;
        if (m==1 and n==1){
                return false;
        }
        return true;
        
    }
};