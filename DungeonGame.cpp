#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        
        int m = dungeon.size(), n = dungeon[0].size();
        
        vector<vector<int> > dp(m, vector<int>(n));
        dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 && j == n-1){
                    continue;
                }
                if(i == m-1){
                    dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
                }else if(j == n-1){
                    dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
                }else{
                    dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1);
                }
            }
        }
        
        return dp[0][0];
        
    }
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    vector<vector<int> > dungeon;
    for(int i=0;i<m;i++){
        vector<int> raw;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            raw.push_back(num);
        }
        dungeon.push_back(raw);
    }
    
    Solution *solution = new Solution();
    cout<<solution->calculateMinimumHP(dungeon);
    
    return 0;
    
}
