#include<iostream>
#include<vector>

using namespace std;

class MinStack {
public:
    vector<int> stack;
    int min;
    MinStack() {
        
    }
    
    void push(int x) {
        if(stack.empty()){
            min = x;
            stack.push_back(min);
        }else if(x<=min){
            stack.push_back(min);
            min = x;
        }
        stack.push_back(x);
    }
    
    void pop() {
        if(stack.back() == min){
            stack.pop_back();
            min = stack.back();
            stack.pop_back();
        }else{
            stack.pop_back();
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min;
    }
};

int main(){
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout<<minStack->getMin()<<endl;
    minStack->pop();
    cout<<minStack->top()<<endl;
    cout<<minStack->getMin()<<endl;
    
    return 0;
}
