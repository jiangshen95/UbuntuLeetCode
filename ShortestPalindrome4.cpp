#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        string t = s + "#" + s_rev;
        int palinLen = getCommenLength(t);
        
        //string result = s.substr(palinLen);
        //reverse(result.begin(), result.end());
        string result = s_rev.substr(0, s.length() - palinLen);
        result += s;
        return result;
        
    }
    
    int getCommenLength(string s){
        
        vector<int> next(s.length(), 0);
        
        for(int i=1;i<s.length();i++){
            int k = next[i-1];
            while(k > 0 && s[k] != s[i]) k = next[k - 1];
            if(s[k] == s[i]) next[i] = k + 1;
        }
        
        return next.back();
    }
};

int main(){
    
    string s;
    cin>>s;
    
    Solution *solution = new Solution();
    cout<<solution->shortestPalindrome(s);
    
    return 0;
    
}
