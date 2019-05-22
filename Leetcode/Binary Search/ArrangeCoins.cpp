class Solution {
public:
    int arrangeCoins(int n) {
        long long lo = 0;
        long long hi = 2000000000;
        while(lo < hi){
            long long mid = lo + ((hi - lo + 1)/2);
            if( mid*(mid + 1)/2  <= n){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};

