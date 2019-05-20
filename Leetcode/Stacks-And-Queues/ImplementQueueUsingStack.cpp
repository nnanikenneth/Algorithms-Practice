// we use two stacks for the operations
// one an enqueue stack and one a dequeue stack
// https://www.youtube.com/watch?v=Wg8IiY1LbII


// so the solution to this problem is to maintain two stacks when we enqueue we just push to the enqueuestack but to pop you pop from the dequeue stack
// when the dequeue stack is empty, just turn over all the contents of the enqueue stack into the dequeue stack

// the fastest solution is to use a linked list, then we just have O(1) operations for enqueue and dequeue operations


class MyQueue {
public:
    /** Initialize your data structure here. */
    
    stack<int> enqueueStack;
    stack<int> dequeueStack;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        enqueueStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int frontValue = 0;
        bool isEmpty = true;
        
        if(dequeueStack.size() == 0){
            while(enqueueStack.size() != 0){
                isEmpty = false;
                int topValue = enqueueStack.top();
                enqueueStack.pop();
                dequeueStack.push(topValue);
            }
            frontValue = dequeueStack.top();
            dequeueStack.pop();
        }else{
            isEmpty = false;
            frontValue = dequeueStack.top();
            dequeueStack.pop();
        }
        
        if(isEmpty)return -1;
        return frontValue;
    }
    
    /** Get the front element. */
    int peek() {
        int frontValue = 0;
        bool isEmpty = true;
        
        if(dequeueStack.size() == 0){
            while(enqueueStack.size() != 0){
                isEmpty = false;
                int topValue = enqueueStack.top();
                enqueueStack.pop();
                dequeueStack.push(topValue);
            }
            frontValue = dequeueStack.top();
        }else{
            isEmpty = false;
            frontValue = dequeueStack.top();
        }
        
        if(isEmpty)return -1;
        return frontValue;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return dequeueStack.size() == 0 && enqueueStack.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */