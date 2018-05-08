#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        
        vector<int> stack;
        int num = 0, result = 0;
        int sign = 1;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i] - '0';
            }else if(s[i] == '+'){
                result += num * sign;
                num = 0;
                sign = 1;
            }else if(s[i] == '-'){
                result += num * sign;
                num = 0;
                sign = -1;
            }else if(s[i] == '('){
                stack.push_back(result);
                stack.push_back(sign);
                sign = 1;
                num = 0;
                result = 0;
            }else if(s[i] == ')'){
                result += num * sign;
                result *= stack.back();
                stack.pop_back();
                result += stack.back();
                stack.pop_back();
                num = 0;
            }
        }
        
        if(num != 0) result += num * sign;
        return result;
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
