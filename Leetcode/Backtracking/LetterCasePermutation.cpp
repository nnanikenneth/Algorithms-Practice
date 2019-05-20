class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<char> val;
        vector<int> loc;
        for(int i = 0; i < S.size(); i++){
            if( (S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z') ){
                val.push_back(S[i]);
                loc.push_back(i);
            }
        }
        vector<string> output;
        for(int i = 0; i < ( 1 << (val.size()) ); i++){
            int t = i;
            string temp = S;
            for(int j = 0; j < val.size(); j++){
                if( (t >> j) & 1  ){
                     char h = toupper(temp[loc[j]]);
                     temp[loc[j]] = h;
                }else{
                     char h = tolower(temp[loc[j]]);
                     temp[loc[j]] = h;
                }
            }
            output.push_back(temp);
        }
        return output;
    }
};