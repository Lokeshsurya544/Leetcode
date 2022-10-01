// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int l=0, r=n, res=0;
        while (l<=r){
            long int mid=(l+r)/2;
            if (isBadVersion(mid)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};