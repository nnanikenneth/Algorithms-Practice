class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> accum;
        partitionHelper(s, 0, accum, res);
        return res;
    }
    
    bool partitionHelper(string &s, int index, vector<string> &accum, vector<vector<string>> &res){
        if(index == s.size()){
            return true;
        }
        
        for(int i = index; i < s.size(); i++) {
            
            string temp = s.substr(index, i - index + 1);
                        
            if( isPalindrome(temp) ) {
                accum.push_back(temp);
                if(partitionHelper(s, i + 1, accum, res)) {
                    res.push_back(accum);
                }
                accum.pop_back();  
            }
        }
        return false;
    }
    
    bool isPalindrome(string &t){
        int i = 0;
        int j = t.size() - 1;
        while(i < j){
            if(t[i] != t[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};