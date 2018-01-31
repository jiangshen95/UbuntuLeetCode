#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if(triangle.empty()) return 0;
        vector<int> dp(triangle.back());
        
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j] = (dp[j]>dp[j+1]?dp[j+1]:dp[j]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
};

int main(){
    vector<vector<int> > triangle;
    
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        vector<int> row;
        for(int j=0;j<i;j++){
            int num;
            cin>>num;
            row.push_back(num);
        }
        triangle.push_back(row);
    }
    
    Solution *solution=new Solution();
    cout<<solution->minimumTotal(triangle);
    
    return 0;
}
