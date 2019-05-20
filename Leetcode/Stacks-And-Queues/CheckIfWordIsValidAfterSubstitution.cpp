// SOLUTION:

// the solution comes from the fact that in the last abc inserted we encounter this
// remove it the other abc will just fall down and match until nothing is left

// we need to keep removing the strings abc from the string and let the rest fall in place
// if nothing is left we are done and the string is valid

class Solution {
public:
    bool isValid(string S) {
        stack<char> st;
        vector<char> word(3, '0');
        vector<char> match = {'a', 'b', 'c'};
        
        for(int i = 0; i < S.size(); i++){
            word[0] = word[1];
            word[1] = word[2];
            word[2] = S[i];
            
            st.push(S[i]);
            if(word == match){
                /// Now to pop the three elements at the top of the stack
                st.pop();
                st.pop();
                st.pop();
                
                /// Now rebuild word with elements from the stack
                // if there is just a single element on the stack
                if(st.size() == 1){
                    char first = st.top();
                    word[0] = ' '; // some dummy char
                    word[1] = ' ';
                    word[2] = first;
                }
                // if there is more than one we just need to rebuild with the last two characters
                // this is because if we the last three were to form a match we could have removed
                // them so we can rebuild with just the last two
                if(st.size() >= 2){
                    char first = st.top();
                    st.pop();
                    
                    char second = st.top();
                    word[1] = second;
                    word[2] = first;
                    word[0] = ' '; ///some dummy character
                    st.push(first);
                }
                if(st.size() == 0){
                    word[0] = ' ';
                    word[1] = ' ';
                    word[2] = ' ';
                }
                
            }
        }
        
        // now if the stack is empty, we are done 
        if(st.size() != 0){
            return false;
        }
        return true;
    }
};