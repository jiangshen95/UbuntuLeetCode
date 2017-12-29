#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        int len=s.length();
        
        vector<string> result;
        string one="";
        
        for(int i=0;i<3&&i<len-3;i++){
            for(int j=i+1;j<i+4&&j<len-2;j++){
                for(int k=j+1;k<j+4&&k<len-1;k++){
                    string s1=s.substr(0, i+1), s2=s.substr(i+1, j-i), s3=s.substr(j+1, k-j), s4=s.substr(k+1, len-k);
                    cout<<"s1: "<<s1<<endl;
                    cout<<"s2: "<<s2<<endl;
                    cout<<"s3: "<<s3<<endl;
                    cout<<"s4: "<<s4<<endl;
                    if(isValid(s1)&&isValid(s2)&&isValid(s3)&&isValid(s4)){
                        result.push_back(s1+"."+s2+"."+s3+"."+s4);
                    }
                }
            }
        }
        
        return result;
        
    }
    
    bool isValid(string s){
        
        int x=0;
        for(int i=0;i<s.length();i++) x=x*10+s[i]-'0';
        
        if(s.length()>3||s.length()==0||(s[0]=='0'&&s.length()>1)||x>255) return false;
        else return true;
    }
    
};

int main(){
    
    string s;
    cin>>s;
    
    vector<string> result;
    Solution *solution=new Solution();
    result=solution->restoreIpAddresses(s);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    
    return 0;
    
}
