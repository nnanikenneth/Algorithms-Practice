class Solution {
public:
    vector<string> restoreIpAddresses(string &s) {
        if(s.size() > 12)return {};
        vector<string> accum;
        vector<string> res;
    
        restoreIpAddressesHelper(s, accum, res);
        return res;
    }
    
    
    bool restoreIpAddressesHelper(string s, vector<string> accum, vector<string> &res){
        if(s.size() == 0 ){
            if(accum.size() == 4){
                return true;
            }
            return false;
        }
        
        for(int i = 1; i <= s.size(); i++){
            string t = s.substr(0, i);
            string recu = s.substr(i, s.size() - i);

            if(t.size() <= 3 && stoi(t) < 256 && stoi(t) >= 0){
                if( isIpNumber(t) ){
                    accum.push_back(t);
                    if( restoreIpAddressesHelper(recu, accum, res) == true ){
                        string temp = "";
                        for(int j = 0; j < accum.size(); j++){
                            temp = temp + accum[j];
                            if(j != accum.size() - 1)temp.push_back('.');
                        }
                        res.push_back(temp);
                    }
                    accum.pop_back();
                }
                
            }
        }
        return false;
    }
    
    bool isIpNumber(string t){
        if(t.size() <= 1){
            return true;
        }
        
        if( t.size() > 1 && (t[0] == '0' && t[1] == '0') ){
            return false;
        }
         
        if( t.size() > 1 && (t[0] == '0' && t[1] != '0') ){
            return false;
        }
        return true;
    }
};