#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> one;
        getCombine(1, k, n, one, result);
        return result;
    }
    
    void getCombine(int i, int k, int n, vector<int>& one, vector<vector<int> >& result){
        if(k==0){
            result.push_back(one);
        }else{
            for(int j=i;j<=n;j++){
                one.push_back(j);
                getCombine(j+1, k-1, n, one, result);
                one.pop_back();
            }
        }
        
    }
};

int main(){
    int n, k;
    cin>>n>>k;
    
    vector<vector<int> > result;
    Solution *solution=new Solution();
    result=solution->combine(n, k);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

