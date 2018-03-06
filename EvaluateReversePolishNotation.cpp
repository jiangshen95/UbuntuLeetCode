#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        vector<int> stack;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int b = stack.back();
                stack.pop_back();
                int a = stack.back();
                stack.pop_back();
                int c;
                switch(tokens[i][0]){
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = a - b;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = a / b;
                        break;
                }
                stack.push_back(c);
            }else{
                stack.push_back(stringToInt(tokens[i]));
            }
        }
        
        return stack.back();
        
    }
    
    int stringToInt(string s){
        int num=0;
        int symble = 1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='-'){
                symble = -1;
                continue;
            }
            num = num*10 + s[i]-'0';
        }
        
        return num*symble;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<string> tokens;
    for(int i=0;i<n;i++){
        string token;
        cin>>token;
        tokens.push_back(token);
    }
    
    Solution *solution = new Solution();
    cout<<solution->evalRPN(tokens);
    
    return 0;
}
