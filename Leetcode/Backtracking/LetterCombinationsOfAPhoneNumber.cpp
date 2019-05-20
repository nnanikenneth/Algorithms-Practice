class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> combine = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
            
        vector<string> combinations;
            
        getLetterCombinations(digits, 0, combine, combinations, "");
        return combinations;
    }
        
    bool getLetterCombinations(string digits, int digitsIndex, map<char, string> combine, vector<string> &results, string accum){
        if(digitsIndex == digits.size()){
            return true;
        }
        
        char currentDigit = digits[digitsIndex];
        
        for(int i = 0; i < combine[currentDigit].size(); i++){
            accum.push_back(combine[currentDigit][i]);
            if(getLetterCombinations(digits, digitsIndex + 1, combine, results, accum) == true){
                   results.push_back(accum);
            }
            accum.pop_back();
        }
        return false;
    }
};