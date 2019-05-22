// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long hi = n;
        long long lo = 1;
        while(lo < hi){
            int mid = (hi + lo)/2;
            if(isBadVersion(mid) == true){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return hi;
    }
};