#include<iostream>
#include<vector>

using namespace std;

class MinStack {
public:
    vector<int> stack;
    vector<int> min_num;
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if(min_num.empty()){
            min_num.push_back(x);
        }else{
            min_num.push_back(min(x, min_num.back()));
        }
    }
    
    void pop() {
        stack.pop_back();
        min_num.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_num.back();
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
