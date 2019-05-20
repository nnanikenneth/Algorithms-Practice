class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n == 0){
            return vector<vector<int>>();
        }
        vector<vector<int>> output;
        vector<int> temp;
        vector<bool> check(n + 1, false);
        int state = 0;
        combineHelper(n, k, state, temp, check, output);
        return output;
    }
    
    bool combineHelper(int n, int k, int state, vector<int> temp, vector<bool> check, vector<vector<int>>& output){
        if(state == k){
            
            return true;
        }
        
        for(int i = 1; i < check.size(); i++){
            if(check[i] == false){
                temp.push_back(i);
                check[i] = true;
                state++;
                if(combineHelper(n, k, state, temp, check, output)){
                    output.push_back(temp);
                }
                state--;
                temp.pop_back();
            }
        }
        return false;
    }
};