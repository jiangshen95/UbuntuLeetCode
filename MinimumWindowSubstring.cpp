/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int start=0, end=0, rs_l=0, rs_r=0;
        int minsize=0;
        for(;end<s.length();end++){
            if(isContain(s, t, start, end)){
                for(int i=start+1;i<=end;i++){
                    if(isContain(s, t, i, end)){
                        start=i;
                    }
                }
                if(end-start+1<minsize||minsize==0){
                    minsize=end-start+1;
                    rs_l=start;
                    rs_r=end;
                }
            }
        }
        if(minsize==0) return "";
        else{
            return s.substr(rs_l, rs_r-rs_l+1);
        }
    }
    
    bool isContain(string s, string t, int start, int end){
        
        int i, j;
        
        for(i=0;i<t.length();i++){
            for(j=start;j<=end;j++){
                if(s[j]==t[i]){
                    s[j]=' ';
                    break;
                }
            }
            if(j==end+1){
                return false;
            }
        }
        
        return true;
    }
};

int main(){
    string s, t;
    cin>>s;
    cin>>t;
    
    Solution *solution=new Solution();
    cout<<solution->minWindow(s, t);
    
    return 0;
}
