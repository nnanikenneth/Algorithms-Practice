class Solution {
public:
    
    int countArrangement(int N) {
        int ans = 0;
        vector<bool> seen(N + 1, 0);
        int used = 0;
        countArrangementHelper(N, seen, 1, ans, used);
        return ans;
    }
    
    bool countArrangementHelper(int N, vector<bool> &seen, int i, int &ans, int used){
       if(used == N){
           return true;
       }
        
       for(int k = 1; k <= N; k++){
           if(seen[k] == false){
               if(i%k == 0 || k%i == 0){
                   seen[k] = true;
                   if( countArrangementHelper(N, seen, i + 1, ans, used + 1) == true){
                        ans++;
                   }
                   seen[k] = false;
               }
           }
       }
       return false;

    }
};