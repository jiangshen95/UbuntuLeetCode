#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int temp[m];
        
        temp[0]=1;
        
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(i==0&&j==0){
                    if(obstacleGrid[i][j]) temp[i]=0;
                    continue;
                }
                if(obstacleGrid[i][j]) temp[i]=0;
                else{
                    temp[i]=(j-1>=0 ? temp[i] : 0) + (i-1>=0 ? temp[i-1] : 0);
                }
            }
        }
        
        return temp[m-1];
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    vector<vector<int> > obstacleGrid;
    
    for(int i=0;i<m;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            int grid;
            cin>>grid;
            row.push_back(grid);
        }
        obstacleGrid.push_back(row);
    }
    
    Solution *solution=new Solution();
    cout<<solution->uniquePathsWithObstacles(obstacleGrid);
    
    return 0;
}
