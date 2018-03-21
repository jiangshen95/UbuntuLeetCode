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
            stack.push_back(0);
        }else{
            stack.push_back(x-min);
            if(x<min) min = x;
        }
    }
    
    void pop() {
        int back = stack.back();
        stack.pop_back();
        if(back<0) min = min-back;
    }
    
    int top() {
        int back = stack.back();
        if(back>0){
            return back+min;
        }else{
            return min;
        }
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
