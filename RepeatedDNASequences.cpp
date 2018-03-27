/*
 * 每次遇到此类题目，都要复习一次KMP算法。
 */
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> result;
        
        if(s.length()<10) return result;
        
        for(int i=0;i<s.length()-9;i++){
            string w = s.substr(i, 10);
            // 或者写成如下：
            // if(map[w]++ == 1) result.push_back(w);
            if(map.find(w) == map.end()){
                map[w] = 1;
            }else{
                if(map[w] == 1) result.push_back(w);
                map[w] ++;
            }
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
