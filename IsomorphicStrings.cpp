#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        for(unsigned int i=0;i<s.length();i++){
            if(map.find(s[i]) == map.end()){
                for(unsigned int j=0;j<i;j++){
                    if(t[j] == t[i]) return false;
                }
                map[s[i]] = t[i];
            }else{
                if(map[s[i]] != t[i]) return false;
            }
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
