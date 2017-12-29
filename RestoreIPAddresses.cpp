#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> result;
        string one="";
        
        restoreIpAddresses(result, one, s, 0, 0);
        
        return result;
        
    }
    
    void restoreIpAddresses(vector<string>& result, string one, string s, int curr, int count){
        
        int x=0;
        
        if(count>=4){
            return;
        }
        
        for(int i=curr;i<s.length()&&i<curr+3;i++){
            x=x*10+s[i]-'0';
            if(s[curr]=='0'&&i>curr) break;
            if(x<256){
                cout<<"-----"<<s.substr(curr, i-curr+1)<<"------"<<endl;
                cout<<"one: "<<one<<endl;
                if(i==s.length()-1&&count==3){
                    result.push_back(one+s.substr(curr, i-curr+1));
                }else{
                    restoreIpAddresses(result, one+s.substr(curr, i-curr+1)+".", s, i+1, count+1);
                }
            }else{
                break;
            }
        }
    }
    
    /*void restoreIpAddresses(vector<string>& result, string one, string s, int curr, int count){
        
        int x=0;
        
        if(count>=4){
            return;
        }
        
        for(int i=curr;i<s.length();i++){
            x=x*10+s[i]-'0';
            if(x<256){
                cout<<"-----"<<s.substr(curr, i-curr+1)<<"------"<<endl;
                cout<<"one: "<<one<<endl;
                if(i==s.length()-1&&count==3){
                    result.push_back(one+s.substr(curr, i-curr+1));
                }else{
                    restoreIpAddresses(result, one+s.substr(curr, i-curr+1)+".", s, i+1, count+1);
                }
            }else{
                break;
            }
        }
    }*/
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
