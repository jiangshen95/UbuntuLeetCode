#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        
        int result = 0;
        int cur = 0;
        char sign = '+';
        
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c == ' ') continue;
            if(c >= '0' && c <= '9'){
                int num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                i --;
                if(sign == '+') cur += num;
                else if(sign == '-') cur -= num;
                else if(sign == '*') cur *= num;
                else if(sign == '/') cur /= num;
            }else{
                if(c == '+' || c == '-') {
                    result += cur;
                    cur = 0;
                }
                sign = c;
            }
        }
        
        return result + cur;
    }
};

int main(){
    
    string s;
    getline(cin, s);
    
    Solution *solution = new Solution();
    cout<<solution->calculate(s);
    
    return 0;
    
}
