#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        
        reverse(s, 0, s.length()-1);
        
        int storeIndex = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                if(storeIndex!=0) s[storeIndex++] = ' ';
                int j = i;
                while(j<s.length()&&s[j]!=' '){
                    s[storeIndex++] = s[j++];
                }
                reverse(s, storeIndex-(j-i), storeIndex-1);
                i = j;
            }
        }
        
        s.erase(s.begin()+storeIndex, s.end());
        
    }
    
    void reverse(string &s, int begin, int end){
        while(begin<end){
            char temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
            begin++;
            end--;
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
