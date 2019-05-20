//each backspace corresponds to a pop on the stack if there is an elements
//and also if there is no element
//add to the stack when you see a character

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stS = process(S);
        stack<char> stT = process(T);
        
        return stS == stT;
    }
    
    
    stack<char> process(const string &s){
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(st.size() != 0){
                    st.pop();
                }
            }else{
                st.push(s[i]);
            }
        }
        return st;
    }
};