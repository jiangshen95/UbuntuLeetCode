#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        vector<string> partitions;
        partition(result, partitions, 0, s);
        return result;
    }
    
    void partition(vector<vector<string> >& result, vector<string>& partitions, int index, string s){
        if(index==s.length()){
            result.push_back(partitions);
        }
        for(int i=index;i<s.length();i++){
            int l=index, r=i;
            while(l<r){
                if(s[l]!=s[r]) break;
                l++;
                r--;
            }
            if(l>=r){
                partitions.push_back(s.substr(index, i-index+1));
                partition(result, partitions, i+1, s);
                partitions.pop_back();
            }
        }
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
