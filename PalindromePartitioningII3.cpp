#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<int> cut(n+1, 0);
        for(int i=0;i<=n;i++) cut[i]=i-1;
        for(int i=0;i<n;i++){
            //奇数
            for(int j=0;i-j>=0&&i+j<n&&s[i-j]==s[i+j];j++) cut[i+j+1]=min(cut[i+j+1], cut[i-j]+1);
            //偶数
            for(int j=0;i-j+1>=0&&i-j+1<n&&i+j<n&&s[i-j+1]==s[i+j];j++) cut[i+j+1]=min(cut[i+j+1], cut[i-j+1]+1);
        }
        return cut[n];
    }
};

int main(){
    string s;
    cin>>s;
    
    Solution *solution=new Solution();
    cout<<solution->minCut(s);
    
    return 0;
}
