class Solution {
public:
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        map<int, bool> seen;
        vector<int> temp;
        combinationSum3Helper(k, n, 0, seen, temp, res);
        return res;
    }
    
    bool combinationSum3Helper(int k, int n, int curSum, map<int, bool> &seen, vector<int> &temp, vector<vector<int>> &res){
        if(curSum == n){
            if(temp.size() == k){
                return true;
            }
            return false;
        }
        
        if(seen.size() == 9){
            if(curSum == n){
                return true;
            }
            return false;
        }
        
        for(int i = 1; i <= 9; i++){
            if(seen.count(i) == 0){ //try ones we did not try before
                //take elements when we have a previous element already contained
                //we make sure we have them in increaing order
                if(temp.size() > 0 && temp[temp.size() - 1] < i){ //only taking elements in increasing order
                    temp.push_back(i);
                    seen[i] = true;
                    if(combinationSum3Helper(k, n, curSum + i, seen, temp, res)){res.push_back(temp);}
                    seen.erase(i);
                    temp.pop_back();
                }else if(temp.size() == 0){ //here we are taking elements when we have an empty array
                    temp.push_back(i);
                    seen[i] = true;
                    if(combinationSum3Helper(k, n, curSum + i, seen, temp, res)){res.push_back(temp);}
                    seen.erase(i);
                    temp.pop_back();
                }
                
            }
        }
        return false;
    }
};
