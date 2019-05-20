class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        getFibonacciSeq(S, 0, {}, res, 0, 0);
        return res;
    }
    
    bool getFibonacciSeq(string &initialString, int m, vector<int> accum, vector<int> &res, long long prev1, long long prev2){
        
        if(m == initialString.size()){
            return true; 
        }
        
        for(int i = m; i < initialString.size(); i++) {
                string temp = initialString.substr(m, i - m + 1);
            
                    if(!(temp[0] == '0' && temp.size() > 1)){
                        if( isIntRange(temp) == true){
                            
                            long long value = stoll(temp);
    
                            if(accum.size() == 2){ //for case 3 when we have two elements we compute prev1 and prev2 to make use subsequently
                            
                                if( value == (long long)accum[0] + (long long)accum[1]) {
                                    accum.push_back(value);
                                    prev1 = accum[1];
                                    prev2 = value;
                                    if( getFibonacciSeq(initialString, i + 1, accum, res, prev1, prev2) == true ){
                                        if(accum.size() > 2){
                                            res = accum;
                                        }
                                    }
                                    accum.pop_back();
                                }
                            }else if(accum.size() > 2){ //for case 2 when we have elements greater than 2 we take into account prev1 and prev2
                                if(value == prev1 + prev2){
                                    accum.push_back(value);
                                    prev1 = accum[accum.size() - 2];
                                    prev2 = accum[accum.size() - 1];
                                    if( getFibonacciSeq(initialString, i + 1, accum, res, prev1, prev2) == true ){
                                        if(accum.size() > 2){
                                            res = accum;
                                        }
                                    }
                                    accum.pop_back();
                                }
                            }else{ //for case 1 when we have elements zero or one in accum
                                accum.push_back(value);
                                if( getFibonacciSeq(initialString, i + 1, accum, res, prev1, prev2) == true ){
                                    if(accum.size() > 2){
                                        res = accum;
                                    }
                                }
                                accum.pop_back();
                            }
                        }
                    }   
               
        }
        return false;
    }
    
    bool isIntRange(string &nums){        
        if(nums.size() < 10){
            return true;
        }
        if(nums.size() == 10){
            int maxInt = (1 << 31) - 1;
            string maxStringVal = to_string(maxInt);
            if(nums <= maxStringVal){
                return true;
            }else{
                return false;
            }
        }
        return false; //nums.size() > 10
    }
};