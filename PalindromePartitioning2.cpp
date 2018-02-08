#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<vector<string> > > result(s.length()+1);
        vector<string> one;
        result[0].push_back(one);
        
        vector<vector<bool> > pair(s.length(), vector<bool>(s.length(), false));
        
        for(int i=0;i<s.length();i++){
            for(int left=0;left<=i;left++){
                if(s[left]==s[i]&&(i-left<=1 || pair[left+1][i-1])){
                    pair[left][i]=true;
                    string str=s.substr(left, i-left+1);
                    for(int j=0;j<result[left].size();j++){
                        vector<string> temp=result[left][j];
                        temp.push_back(str);
                        result[i+1].push_back(temp);
                    }
                }
            }
        }
        
        return result[s.length()];
    }
    
};

int main(){
    string s;
    cin>>s;
    
    Solution *solution=new Solution();
    vector<vector<string> > result=solution->partition(s);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
