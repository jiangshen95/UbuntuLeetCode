#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                if(count==0){
                    continue;
                }
                break;
            }
            count++;
        }
        
        return count;
        
    }
};

int main(){
    string s;
    getline(cin,s);
    
    Solution *solution=new Solution();
    
    cout<<s<<endl;
    
    cout<<solution->lengthOfLastWord(s);
    
    return 0;
}
