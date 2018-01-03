#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        return isInterleave(s1, 0, s2, 0, "", s3);
        
    }
    
    bool isInterleave(string s1, int i, string s2, int j, string res, string s3){
        if(res==s3&&i==s1.length()&&j==s2.length()){
            return true;
        }
        bool ans=false;
        if(i<s1.length())
            ans |= isInterleave(s1, i+1, s2, j, res+s1[i], s3);
        if(j<s2.length())
            ans |= isInterleave(s1, i, s2, j+1, res+s2[j], s3);
        return ans;
    }
    
};

int main(){
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    
    Solution *solution=new Solution();
    solution->isInterleave(s1, s2, s3) ? cout<<"True" : cout<<"False";
    
    return 0;
}
