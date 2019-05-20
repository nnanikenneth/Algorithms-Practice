class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i = 0; i < tokens.size(); i++){
            if(!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")){
                st.push(tokens[i]);
                continue;
            }else{
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    string tempres = to_string(evaluate(first) + evaluate(second) );
                    st.push(tempres);
                }
                if(tokens[i] == "-"){
                    string tempres = to_string(evaluate(second) - evaluate(first) );
                    st.push(tempres);
                }
                if(tokens[i] == "*"){
                    string tempres = to_string(evaluate(first) * evaluate(second) );
                    st.push(tempres);
                }
                if(tokens[i] == "/"){
                    string tempres = to_string(evaluate(second) / evaluate(first) );
                    st.push(tempres);
                }
            }
        }
        return (evaluate( st.top() ) );
    }
    
    int evaluate(string num){
        int ret = 0;
        bool flag = false; //is positive
        if(num[0] == '-'){
            flag = true;
        }
        if(flag == true){
           for(int i = 1; i < num.size(); i++){
                ret = ret * 10 + (num[i] - '0');
           } 
        }else{
           for(int i = 0; i < num.size(); i++){
                ret = ret * 10 + (num[i] - '0');
           } 
        }
        if(flag)return -ret;
            else
                return ret;
    }
};