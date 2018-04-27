/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string result = "";
        int i;
        for(i = s.length()-1;i>=0;i--){
            if(isPalindrome(s, 0, i)) break;
        }
        for(int j = i + 1;j<s.length();j++){
            result = s[j] + result;
        }
        result += s;
        
        return result;
        
    }
    
    bool isPalindrome(string s, int begin, int end){
        for(;begin<end && s[begin] == s[end];begin++, end--);
        return begin >= end;
    }
};

int main(){
    
    string s;
    cin>>s;
    
    Solution *solution = new Solution();
    cout<<solution->shortestPalindrome(s);
    
    return 0;
    
}
