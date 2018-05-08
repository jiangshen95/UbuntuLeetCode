#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> stack;
        vector<int> operat;
        
        int num = 0;
        char lastOperator = 'x';
        for(int i=0;i<s.length();i++){
            
            cout<<"numStack: ";
            for(int j=0;j<stack.size();j++) cout<<stack[j]<<" ";
            cout<<endl;
            cout<<"operator: ";
            for(int j=0;j<operat.size();j++) cout<<operat[j]<<" ";
            cout<<endl;
            cout<<"num: "<<num<<endl;
            
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i] - '0';
            }else if(s[i] == '+' || s[i] == '-'){
                if(lastOperator == '(' || lastOperator == 'x'){
                    s[i] == '+' ? operat.push_back(1) : operat.push_back(-1);
                    stack.push_back(num);
                }else if(lastOperator == '+' || lastOperator == '-'){
                    num = num * operat.back() + stack.back();
                    operat.pop_back();
                    stack.pop_back();
                    stack.push_back(num);
                    s[i] == '+' ? operat.push_back(1) : operat.push_back(-1);
                }else if(lastOperator == ')'){
                    if(!operat.empty()){
                        num = num * operat.back() + stack.back();
                        operat.pop_back();
                        stack.pop_back();
                    }
                    stack.push_back(num);
                    s[i] == '+' ? operat.push_back(1) : operat.push_back(-1);
                }
                num = 0;
                lastOperator = s[i];
            }else if(s[i] == '('){
                num = 0;
                lastOperator = s[i];
            }else if(s[i] == ')'){
                if(!operat.empty() && lastOperator != '('){
                    num = num * operat.back() + stack.back();
                    operat.pop_back();
                    stack.pop_back();
                    //stack.push_back(num);
                }
                lastOperator = s[i];
            }
        }
        cout<<"num: "<<num<<endl;
        if(stack.empty()) return num;
        if(operat.empty()) return stack.back();
        else return stack.back() + num * operat.back();
    }
};

int main(){
    
    string s;
    getline(cin, s);
    
    //cout<<s;
    
    Solution *solution = new Solution();
    cout<<solution->calculate(s);
    
    return 0;
    
}
