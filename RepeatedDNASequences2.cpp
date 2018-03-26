#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> result;
        if(s.length()<10) return result;
        
        unordered_map<int, int> map;
        
        for(int i=0;i<s.length()-9;i++){
            int v = 0;
            for(int j = i;j<i+10;j++){
                v <<= 2;
                switch(s[j]){
                    case 'A':
                        break;
                    case 'C':
                        v |= 1;
                        break;
                    case 'G':
                        v |= 2;
                        break;
                    case 'T':
                        v |= 3;
                        break;
                }
            }
            if(map[v]++ == 1){
                result.push_back(s.substr(i, 10));
            }
            /*if(map.find(v) == map.end()){
                map[v] = 1;
            }else{
                if(map[v] == 1) result.push_back(s.substr(i, 10));
                map[v] ++;
            }*/
        }
        
        return result;
    }
};

int main(){
    string s;
    cin>>s;
    
    Solution *solution = new Solution();
    vector<string> result = solution->findRepeatedDnaSequences(s);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    
    return 0;
}
