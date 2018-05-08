#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        
        vector<int> sign(2, 1);
        int result = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                int num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i++] - '0';
                }
                i --;
                result += sign.back() * num;
                sign.pop_back();
            }else if(s[i] == ')') sign.pop_back();
            else{
                sign.push_back(sign.back() * (s[i] == '-' ? -1 : 1));
            }
        }
        
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
