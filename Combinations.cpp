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
        if(one.size()==k-1){
            one.push_back(i);
            result.push_back(one);
        }
        else if(one.size()<k-1){
            one.push_back(i);
            for(int j=i+1;j<=n;j++){
                cout<<"j: "<<j<<endl; 
                getCombine(j, k, n, one, result);
                for(int o=0;o<one.size();o++) cout<<one[o]<<" ";
                cout<<endl;
            }
            
        }
        one.pop_back();
        if(i<n&&one.empty()) getCombine(i+1, k, n, one, result);
        
        /*if(one.size()<k){
            for(int j=i;j<=n-k+1;j++){
                one.push_back(j);
                if(one.size()==k){
                    result.push_back(one);
                }
                else{
                    for(int l=j+1;l<=n;l++){
                        getCombine(l, k, n, one, result);
                    }
                }
                one.pop_back();
            }
        }*/
        
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
