#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> iqueue, oqueue;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        iqueue.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        int top = oqueue.top();
        oqueue.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        
        if(oqueue.empty()) {
            while(!iqueue.empty()){
                int top = iqueue.top();
                iqueue.pop();
                oqueue.push(top);
            }
        }
        
        return oqueue.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return iqueue.empty() && oqueue.empty();
    }
};

int main() {
    
    MyQueue queue = MyQueue();
    queue.push(1);
    queue.push(2);
    cout<<queue.pop()<<endl;
    cout<<queue.peek()<<endl;
    cout<<queue.empty()<<endl;
    
    return 0;
        
}
