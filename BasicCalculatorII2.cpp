#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        
        vector<int> nums;
        
        int num = 0;
        char sign = '+';
        
        for(int i=0;i<s.length();i++){
            char c = s[i];
            //if(c == ' ') continue;
            if(c >= '0' && c <= '9'){
                num = num * 10 + s[i] - '0';
            }
            if(c == '+' || c == '-' || c == '*' || c == '/' || i == s.length() - 1){
                if(sign == '+') nums.push_back(num);
                if(sign == '-') nums.push_back(-num);
                if(sign == '*'){
                    num = nums.back() * num;
                    nums.pop_back();
                    nums.push_back(num);
                }
                if(sign == '/') {
                    num = nums.back() / num;
                    nums.pop_back();
                    nums.push_back(num);
                }
                sign = c;
                num = 0;
            }
        }
        
        int result = 0;
        for(int i=0;i<nums.size();i++){
            result += nums[i];
        }
        
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
