#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        
        int n = s.length();
        int i = 0;
        for(int j=n-1;j>=0;j--){
            if(s[j] == s[i]) i++;
        }
        if(i == n) return s;
        
        string remain_rev = s.substr(i);
        cout<<remain_rev<<endl;
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

int main(){
    
    string s;
    cin>>s;
    
    Solution *solution = new Solution();
    cout<<solution->shortestPalindrome(s);
    
    return 0;
    
}

