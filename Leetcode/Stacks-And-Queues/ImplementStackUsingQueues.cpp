class MyStack {
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        int k = 0;
        while(k < que.size() - 1){
            int value = que.front();
            que.pop();
            que.push(value);
            k++;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(que.empty()){
            return -1;
        }
        int value = que.front();
        que.pop();
        return value;
        
    }
    
    /** Get the top element. */
    int top() {
        if(que.empty()){
            return -1;
        }
        int value = que.front();
        return value;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */