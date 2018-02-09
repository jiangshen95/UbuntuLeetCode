/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool> > pair(s.length(), vector<bool>(s.length(), false));
        for(int i=0;i<s.length();i++){
            for(int j=0;j<=i;j++){
                if(s[i]==s[j]&&(i-j<=1||pair[j+1][i-1])) pair[j][i]=true;
            }
        }
        
        int min=s.length()-1;
        minCur(pair, 0, -1, min);
        
        return min;
    }
    
    void minCur(vector<vector<bool> >& pair, int begin, int step, int& min){
        if(begin>=pair.size()){
            cout<<step<<endl;
            if(step<min) min=step;
        }
        for(int i=begin;i<pair.size();i++){
            if(pair[begin][i]){
                minCur(pair, i+1, step+1, min);
            }
        }
    }
};

int main(){
    string s;
    cin>>s;
    
    Solution *solution=new Solution();
    cout<<solution->minCut(s);
    
    return 0;
}
