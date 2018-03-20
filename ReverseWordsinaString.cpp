#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        
        int i = s.length()-1;
        
        while(s[i]==' '){
            i--;
        }
        
        s.erase(i+1, s.length()-i);
        
        int end = s.length();
        
        int j=0;
        while(j<end){
            if(s[j]==' '){
                s.erase(j, 1);
                end--;
                continue;
            }
            for(i=j;i<end&&s[i]!=' ';i++);
            if(i==end) break;
            
            s.insert(end, " "+s.substr(j, i-j));
            
            s.erase(j, i-j);
            end -= i-j;
        }
        
    }
};

int main(){
    string s;
    getline(cin, s);
    
    Solution *solution = new Solution();
    solution->reverseWords(s);
    
    cout<<s;
    
    return 0;
}
