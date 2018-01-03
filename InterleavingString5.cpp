#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int> > memo(s1.length(), vector<int>(s2.length(), -1));
        return isInterleave(s1, 0, s2, 0, s3, 0, memo);
        
    }
    
    bool isInterleave(string s1, int i, string s2, int j, string s3, int k, vector<vector<int> >& memo){
        if(i==s1.length()){
            return s2.substr(j)==s3.substr(k);
        }
        if(j==s2.length()){
            return s1.substr(i)==s3.substr(k);
        }
        if(memo[i][j]>=0) return memo[i][j];
        
        bool ans=false;
        
        if((s1[i]==s3[k]&&isInterleave(s1, i+1, s2, j, s3, k+1, memo))||
        (s2[j]==s3[k]&&isInterleave(s1, i, s2, j+1, s3, k+1, memo))){
            ans=true;
        }
        
        memo[i][j]= ans ? 1 : 0;
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
