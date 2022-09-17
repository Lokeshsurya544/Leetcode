class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n>0){
            // cout<<(n&1)<<endl;
            c+=(n&1);
            n=n>>1;
        }
        return c;
    }
};