class Solution {
public:
    int numSquares(int n) {
        vector<int> squares = findSquares();
        vector<int> memo(n+1, 0);
        return findMin(squares, n, memo); 
    }
    
    int findMin(vector<int> &squares, int n, vector<int> &memo){
        if(n == 1)return 1;
        if(n == 0){
            return 0;
        }
        
        if(memo[n] != 0)return memo[n];
        
        int index = 0;
        int ans = (1 << 31) - 1;
        while(n - squares[index] >= 0 && index < squares.size()){
            int r = findMin(squares, n - squares[index], memo);
            ans = min(ans, r);
            index++;
        }
        
        memo[n] = ans + 1;
        //cout << "The result of findMin( " << n << " ) and discovered the result: " << ans << endl;
        return memo[n];
    }
    
    vector<int> findSquares(){
        vector<int> s;
        for(int i = 1; i < 100; i++){
            s.push_back(i*i);
        }
        return s;
    }

};