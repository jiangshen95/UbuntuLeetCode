#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> stack;
    int topn;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack.push(x);
        topn = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = stack.size();
        for(int i=0;i<size-1;i++){
            stack.push(stack.front());
            topn = stack.front();
            stack.pop();
        }
        int temp = stack.front();
        stack.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return topn;
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
