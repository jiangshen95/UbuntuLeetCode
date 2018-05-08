#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        
        vector<int> nums;
        vector<char> operators;
        
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
                if(!operators.empty() && (operators.back() == '*' || operators.back() == '/')){
                    int pre = nums.back();
                    nums.pop_back();
                    if(operators.back() == '*') num = pre * num;
                    else num = pre / num;
                    operators.pop_back();
                }
                nums.push_back(num);
            }else{
                operators.push_back(c);
            }
        }
        
        int result = nums.front();
        for(int i=0;i<operators.size();i++){
            if(operators[i] == '+'){
                result += nums[i+1];
            }else{
                result -= nums[i+1];
            }
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
