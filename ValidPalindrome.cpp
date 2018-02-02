#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0) return true;
        int l=0, r=s.length()-1;
        while(l<r){
            if(!((s[l]>='a'&&s[l]<='z')||(s[l]>='A'&&s[l]<='Z')||(s[l]>='0'&&s[l]<='9'))){
                l++;
                continue;
            }
            if(!((s[r]>='a'&&s[r]<='z')||(s[r]>='A'&&s[r]<='Z')||(s[r]>='0'&&s[r]<='9'))){
                r--;
                continue;
            }
            if(!(s[l]==s[r]||(s[l]>='a'&&s[l]<='z'&&s[l]==s[r]+32)||(s[l]>='A'&&s[l]<='Z'&&s[l]==s[r]-32))){
                return false;
            }
            cout<<s[l]<<"-----"<<s[r]<<endl;
            l++;
            r--;
        }
        return true;
    }
};

int main(){
    string s;
    getline(cin, s);
    cout<<s<<endl;
    Solution solution=Solution();
    solution.isPalindrome(s)?cout<<"True":cout<<"False";
    
    return 0;
}
