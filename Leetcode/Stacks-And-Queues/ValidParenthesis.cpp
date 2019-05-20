class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.size() == 0)return false; ///some stupid edge case careful here
                char t = st.top();
                st.pop();
                if(!( (t == '[' && s[i] == ']') || (t == '{' && s[i] == '}') || (t == '(' && s[i] == ')') )){
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};