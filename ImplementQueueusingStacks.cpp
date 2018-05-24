#include<iostream>
#include<stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> queue;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while(!queue.empty()){
            temp.push(queue.top());
            queue.pop();
        }
        queue.push(x);
        while(!temp.empty()){
            queue.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = queue.top();
        queue.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return queue.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return queue.empty();
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
