#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool has_point=false, has_e=false;
        bool num_flag=false;
        int i=0, j=s.length()-1;
        while(i<j&&s[i]==' ') i++;
        while(i<j&&s[j]==' ') j--;
        s=s.substr(i, j-i+1);
        //cout<<s<<endl;
        for(i=0;i<s.length();i++){
            //if(s[i]==' '){
            //    return false;
            //}
            if(s[i]=='.'){
                if(has_point || has_e){
                    return false;
                }
                has_point=true;
            }
            else if(s[i]=='e'){
                if(!((!has_e)&&(i>0&&s[i-1]!='+'&&s[i-1]!='-')&&(num_flag))||i==s.length()-1){
                    return false;
                }
                has_e=true;
            }
            else if(s[i]=='+'||s[i]=='-'){
                if(!(i==0 || (i>0&&s[i-1]=='e')) || i==s.length()-1){
                    return false;
                }
            }
            else if(!(s[i]>='0'&&s[i]<='9')){
                return false;
            }
            else{
                num_flag=true;
            }
            
        }
        return num_flag;
    }
};

int main(){
    string s;
    getline(cin, s);
    
    Solution *solution=new Solution();
    if(solution->isNumber(s)) cout<<"True";
    else cout<<"False";
    
    return 0;
}
