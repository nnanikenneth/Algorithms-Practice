class MinStack {
public:
    /** initialize your data structure here. */
    stack< pair<int, int> > st;
    
    MinStack() {
        stack< pair<int, int> > st = this->st;
    }
    
    void push(int x) {
        if(st.size() == 0){
            st.push(make_pair(x, x));
        }else{
            if(x < st.top().second){
                st.push(make_pair(x, x));
            }else{
                st.push(make_pair(x, st.top().second));
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            
        }else{
            st.pop();
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */