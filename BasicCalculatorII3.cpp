#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        
        int result = 0;
        int pre = 0;
        
        int num = 0;
        char sign = '+';
        
        s = '+' + s + '+';
        
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c == ' ') continue;
            if(c >= '0' && c <= '9'){
                num = num * 10 + s[i] - '0';
            }else{
                if(sign == '+') {
                    result += pre;
                    pre = num;
                }
                if(sign == '-') {
                    result += pre;
                    pre = -num;
                }
                if(sign == '*'){
                    pre = pre * num;
                }
                if(sign == '/') {
                    pre = pre / num;
                }
                
                sign = c;
                num = 0;
            }
        }
        
        result += pre;
        
        return result;
    }
};

int main(){
    
    string s;
    getline(cin, s);
    
    Solution *solution = new Solution();
    cout<<solution->calculate(s);
    
    return 0;
    
}
