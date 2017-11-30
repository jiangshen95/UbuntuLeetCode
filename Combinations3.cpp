#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> one(k, 0);
        
        int i=0;
        while(i>=0){
            one[i]++;
            if(one[i]>n) i--;
            else if(i==k-1) result.push_back(one);
            else{
                i++;
                one[i]=one[i-1];
            }
        }
        
        return result;
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

