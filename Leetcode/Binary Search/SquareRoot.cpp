class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0;
        long long hi = 100000000;
        while(lo < hi) {
            long long mid = (hi + lo + 1) >> 1;
            if(mid*mid <= x) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        
        return hi;
    }
};