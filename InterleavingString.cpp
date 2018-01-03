/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        return isInterleave(0, 0, 0, 1, s1, s2, s3)||isInterleave(0, 0, 0, 2, s1, s2, s3);
        
    }
    
    bool isInterleave(int a, int b, int c, int type, string s1, string s2, string s3){
        string t;
        int x;
        if(type==1){
            t=s1;
            x=a;
        }else{
            t=s2;
            x=b;
        }
        
        if(a==s1.length()&&b==s2.length()&&c==s3.length()){
            return true;
        }
        
        for(int i=x;i<t.length();i++){
            if(t[i]==s3[c+i-x]){
                if((type==1&&isInterleave(i+1, b, c+i-x+1, 2, s1, s2, s3))||(type==2&&isInterleave(a, i+1, c+i-x+1, 1, s1, s2, s3))){
                    return true;
                }
            }else{
                return false;
            }
        }
        
        return false;
    }
};

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    
    Solution *solution=new Solution();
    solution->isInterleave(s1, s2, s3) ? cout<<"True" : cout<<"False";
    
    return 0;
}
