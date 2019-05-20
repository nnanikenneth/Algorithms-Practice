class Solution {
public:
    /// so the solution to the problems 
    /// involves keeping track of unbalances withing the string 
    /// which we can do in two ways
    /// we try to balance the string if stack is empty this means 
    /// there exist a matching counterpart 
    /// int the end we take the remants of the stack contents ie stack .size
    /// space opimisation, stack can be simulated with a count
    
    int minAddToMakeValid(string S) {
        int cnt = 0;
        int simulateStack = 0;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '('){
                simulateStack++;
            }else{
                if(simulateStack == 0){
                    cnt++;
                }else{
                    simulateStack--;
                }
            }
        }
        return cnt + simulateStack;
    }
    
    // stack<int> st;
    // int cnt = 0;
    // int simulateStack = 0;
    // for(int i = 0; i < S.size(); i++){
    //     if(S[i] == '('){
    //         simulateStack++;
    //     }else{
    //         if(simulateStack == 0){
    //             cnt++;
    //         }else{
    //             simulateStack--;
    //         }
    //     }
    // }
    // return cnt + simulateStack;
        
};