#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> stack;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size = stack.size();
        stack.push(x);
        for(int i=0;i<size;i++){
            stack.push(stack.front());
            stack.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = stack.front();
        stack.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return stack.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stack.empty();
    }
};

int main(){
    
    MyStack *stack = new MyStack();
    stack->push(1);
    stack->push(2);
    cout<<stack->top()<<endl;
    cout<<stack->pop()<<endl;
    cout<<stack->top()<<endl;
    cout<<stack->pop()<<endl;
    cout<<stack->empty()<<endl;
    
    return 0;
}
