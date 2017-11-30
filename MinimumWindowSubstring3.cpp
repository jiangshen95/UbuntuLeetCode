#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int begin=0, end=0, rs_l=0, rs_r=0;
        int need_to_find[256]={0};
        int counter=t.length();
        int minsize=0;
        
        for(int i=0;i<t.length();i++) need_to_find[t[i]]++;
        
        while(end<s.length()){
            if(need_to_find[s[end++]]-->0) counter--;
            while(counter==0){
                cout<<"begin: "<<begin<<"----"<<"end: "<<end<<endl;
                if(minsize>end-begin || minsize==0){
                    minsize=end-begin;
                    rs_l=begin;
                    rs_r=end-1;
                }
                if(need_to_find[s[begin++]]++>=0) counter++;
            }
        }
        
        if(minsize==0) return "";
        else{
            return s.substr(rs_l, rs_r-rs_l+1);
        }
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

