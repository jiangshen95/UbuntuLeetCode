#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        
        int number = 0;
        for(int i=0;i<s.length();i++){
            number = number*26 + (s[i] - 'A' +1);
        }
        
        return number;
    }
};

int main() {
    
    string s;
    cin>>s;
    
    Solution *solution = new Solution();
    cout<<solution->titleToNumber(s);
    
    return 0;
    
}
