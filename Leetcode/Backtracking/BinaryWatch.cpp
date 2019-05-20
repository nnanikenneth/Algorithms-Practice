class Solution {
public:
    
    vector<int> get(int n, int k) { //putting k bits on in n
        vector<int> output;
        for(int i = 0; i < (1 << n) - 1; i++){
            int bitcount = 0;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    bitcount++;
                }
            }
            if(bitcount == k){
              output.push_back(i);
            }
        }
        return output;
    }
    
    string pad(string ans){
        string res = "";
        if(ans.size() == 1){
            res = "0"+ans;
        }   
        if(ans.size() == 0){
            res = "00";
        }
        return res;
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> output;
        
        for(int i = 0; i <= num; i++) {
            if(i <= 4 && i >= 0 && num - i <= 6 && num - i >= 0) {
                vector<int> a = get(4, i);
                vector<int> b = get(6, num - i);
                for(int k = 0; k < a.size(); k++){
                    for(int l = 0; l < b.size(); l++){
                        int hr = a[k];
                        int mn = b[l];
                        
                        if(hr < 12 && mn < 60) { //according to constraints
                            string hour = to_string(hr);
                            string min = to_string(mn);
                            //pad min accorting to constraints
                            if(min.size() < 2){
                                min = pad(min);
                            }
                            string temp = hour + ":" + min;
                            output.push_back(temp);
                        }
                        
                    }
                }
            }
        }
        
        return output;
    }
};