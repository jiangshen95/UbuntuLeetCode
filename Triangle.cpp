#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if(triangle.empty()) return 0;
        vector<int> dp(triangle.size(), 0);
        dp[0] = triangle[0][0];
        
        for(int i=1;i<triangle.size();i++){
            for(int j=i;j>=0;j--){
                if(j==0) dp[j]+=triangle[i][j];
                else if(j==i) dp[j]=dp[j-1]+triangle[i][j];
                else dp[j] = (dp[j]>dp[j-1]?dp[j-1]:dp[j]) + triangle[i][j];
            }
        }
        int min=dp[0];
        for(int i=1;i<dp.size();i++){
            if(dp[i]<min) min=dp[i];
        }
        
        return min;
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
