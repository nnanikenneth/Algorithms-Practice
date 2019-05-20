class Solution {
public:
    string simplifyPath(string path) {
        if(path == "/")return "/"; //some trick case being handled here (careful)
        
        int k = 0; 
        int j = 0;
        string temp;
        vector<string> s;
        stack<string> stk;
        for(int i = 0; i < path.size(); i++){
            if(path[i] != '/'){
                temp.push_back(path[i]);
            }else{
                if(temp.size() > 0){ //capture data and process from here
                    if(temp == ".."){
                        if(stk.size() != 0){
                            stk.pop();
                        }
                    }
                    //note that you do not handle the case where temp == "." since its equivalent to nothing
                    if(temp != ".." && temp != "."){
                        stk.push(temp);
                    }
                    temp.clear();
                }
               
            }
        }
        
        if(temp.size() > 0){
             if(temp == ".."){
                    if(stk.size() != 0){
                        stk.pop();
                    }
             }
             //note that you do not handle the case where temp == "." since its equivalent to nothing
             if(temp != ".." && temp != "."){
                    stk.push(temp);
             }
        }
        
        if(stk.size() == 0){ //some tricky case i need to handle
            return "/";
        }
        
        string out = "";
        while(stk.size() > 0){
            string t = stk.top();
            reverse(t.begin(), t.end());
            out = out + t  +  "/";
            stk.pop();
        }

        reverse(out.begin(), out.end());
        return out;
    }
};