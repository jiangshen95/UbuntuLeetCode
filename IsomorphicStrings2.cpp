#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256, 0), m2(256, 0);
        for(int i=0;i<s.length();i++){
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

int main(){
    
    string s, t;
    cin>>s;
    cin>>t;
    
    Solution *solution = new Solution();
    solution->isIsomorphic(s, t) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
