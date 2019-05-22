// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long lo = 0;
        long long hi = n;
        while( lo <= hi ){
            long long mid = (lo + hi)/2;
            if(guess(mid) == 0){
                return mid;
            }
            if(guess(mid) == -1){
                hi = mid - 1;
            }
            if(guess(mid) == 1){
                lo = mid + 1;
            }
        }
        return -1;
    }
    
};