#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        
        string t = s;
        t += "#";
        
        for(int i = s.length()-1;i>=0;i--) t += s[i];
        cout<<t<<endl;
        vector<int> next(t.length(), 0);
        
        int k = 0;
        int j = 1;
        while(j < t.length()){
            if(k == 0 && t[j] != t[k]){
                next[j] = k;
                j ++;
            }
            else if(t[j] == t[k]){
                next[j++] = ++k;
            }else{
                k = next[k - 1];
            }
            
        }
        
        int palinLen = next.back();
        string result = "";
        for(int i = palinLen;i<s.length();i++) result = s[i] + result;
        result += s;
        
        return result;
        
    }
};

int main(){
    
    string s;
    cin>>s;
    
    Solution *solution = new Solution();
    cout<<solution->shortestPalindrome(s);
    
    return 0;
    
}
