#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int start=0, end=0, rs_l=0, rs_r=0;
        int has_found[256]={0};
        int need_to_find[256]={0};
        
        for(int i=0;i<t.length();i++) need_to_find[t[i]]++;
        
        int findAll=0;
        int minsize=0;
        for(;end<s.length();end++){
            
            has_found[s[end]]++;
            if(has_found[s[end]]<=need_to_find[s[end]]) findAll++;
            cout<<"----1----"<<endl;
            cout<<"start: "<<start<<"----"<<"end: "<<end<<endl;
            if(findAll==t.length()&&need_to_find[s[end]]){
                for(int i=start;i<=end;i++){
                    has_found[s[i]]--;
                    if(has_found[s[i]]<need_to_find[s[i]]){
                        start=i;
                        has_found[s[i]]++;
                        break;
                    }
                }
                cout<<"----2----"<<endl;
                cout<<"start: "<<start<<"----"<<"end: "<<end<<endl;
                cin.get();
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
};

int main(){
    string s, t;
    cin>>s;
    cin>>t;
    
    Solution *solution=new Solution();
    cout<<solution->minWindow(s, t);
    
    return 0;
}

