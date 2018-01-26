/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int num=0;
        numDistinct(num, s, -1, t, 0);
        return num;
    }
    
    void numDistinct(int& num, string s, int i, string t, int j){
        if(j==t.length()) num++; 
        for(int k=i+1;k<s.length();k++){
            if(s[k]==t[j]) numDistinct(num, s, k, t, j+1);
        }
    }
};

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    
    Solution *solution=new Solution();
    cout<<solution->numDistinct(s, t);
    
    return 0;
}
