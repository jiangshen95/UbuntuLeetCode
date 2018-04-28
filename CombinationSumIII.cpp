#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        
        vector<vector<int> > result;
        vector<int> one;
        findNums(one, result, 0, 0, k, n);
        
        return result;
    }
    
    void findNums(vector<int>& one, vector<vector<int> >& result, int sum, int num, int k, int n){
        if(one.size() == k){
            if(sum == n) result.push_back(one);
            return;
        }
        if(sum > n) return;
        for(int i=num+1;i<=9 && i<=n-sum;i++){
            one.push_back(i);
            findNums(one, result, sum + i, i, k, n);
            one.pop_back();
        }
    }
};

int main(){
    
    int k, n;
    cin>>k>>n;
    
    Solution *solution = new Solution();
    vector<vector<int> > result = solution->combinationSum3(k, n);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    return 0;
    
}
