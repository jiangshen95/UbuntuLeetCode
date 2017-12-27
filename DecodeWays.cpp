#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0||s[0]=='0'){
            return 0;
        }
        
        int num1=1;
        int num2=1;
        int num=1;
        int x;
        for(int i=1;i<s.length();i++){
            
            x=s[i]-'0'+(s[i-1]-'0')*10;
            cout<<"x: "<<x<<endl;
            
            if(x==0||(x>26&&x%10==0)){
                num=0;
                break;
            }
            
            if(i<=1){
                if(x>26||x==10||x==20) num2=1;
                else num2=2;
                num=num2;
            }else{
                if(x>26||x<10) num=num2;
                else if(x==10||x==20) num=num1;
                else{
                    num=num1+num2;
                }
                
                num1=num2;
                num2=num;
            }
        }
        
        return num;
    }
};

int main(){
    string s;
    cin>>s;
    
    Solution *solution=new Solution();
    cout<<solution->numDecodings(s);
    
    return 0;
}
