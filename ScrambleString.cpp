/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        
        cout<<"s1: "<<s1<<endl;
        cout<<"s2: "<<s2<<endl;
        
        for(int i=0;i<s1.length();i++){
            
            if(s1.substr(0, i)+s1.substr(i, s1.length()-i)==s2.substr(i, s2.length()-i)+s2.substr(0, i)){
                return true;
            }
        }
        for(int i=1;i<s1.length();i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i))&&isScramble(s1.substr(i, s1.length()-i), s2.substr(i, s1.length()-i))){
                return true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(s1.length()-i, i))&&isScramble(s1.substr(i, s1.length()-i), s2.substr(0, s1.length()-i))){
                return true;
            }
        }
        return false;
        
    }
};

int main(){
    string s1, s2;
    cin>>s1>>s2;
    
    Solution *solution=new Solution();
    solution->isScramble(s1, s2)?cout<<"True":cout<<"False";
    
    return 0;
}
