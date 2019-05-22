class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lo = 0;
        long long hi = 100000000;
        while(lo < hi) {
            long long mid = (hi + lo) >> 1;
            if(mid*mid >= num) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if(hi*hi == num){
            return true;
        }
        return false;
    }
};