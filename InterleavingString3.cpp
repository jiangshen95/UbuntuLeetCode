#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int len1=s1.length(), len2=s2.length(), len3=s3.length();
        if(len1+len2!=len3) return false;
        bool dp[len2+1];
        dp[0]=true;
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(i==0&&j==0) continue;
                if((j>0&&dp[j-1]&&s2[j-1]==s3[i+j-1])||(i>0&&dp[j]&&s1[i-1]==s3[i+j-1])){
                    dp[j]=true;
                }else{
                    dp[j]=false;
                }
            }
        }
        
        return dp[len2];
        
    }
    
};

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    
    Solution *solution=new Solution();
    solution->isInterleave(s1, s2, s3) ? cout<<"True" : cout<<"False";
    
    return 0;
}
