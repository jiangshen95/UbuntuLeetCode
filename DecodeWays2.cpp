#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0||s[0]=='0'){
            return 0;
        }
        
        int num1, num2;
        num1=1;
        num2=1;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0') num2=0;
            if(s[i-1]=='1' || s[i-1]=='2' && s[i]<='6'){
                num2=num1+num2;
                num1=num2-num1;
            }else{
                num1=num2;
            }
        }
        
        return num2;
        
    }
};

int main(){
    string s;
    cin>>s;
    
    Solution *solution=new Solution();
    cout<<solution->numDecodings(s);
    
    return 0;
}
