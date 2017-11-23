#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int temp[m][n];
        temp[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                if(i==0){
                    temp[i][j]=temp[i][j-1]+grid[i][j];
                }else if(j==0){
                    temp[i][j]=temp[i-1][j]+grid[i][j];
                }else{
                    temp[i][j] = (temp[i-1][j]>temp[i][j-1] ? temp[i][j-1] : temp[i-1][j])+grid[i][j];
                    cout<<temp[i][j]<<endl;
                }
            }
        }
        
        return temp[m-1][n-1];
        
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    vector<vector<int> > grid;
    
    for(int i=0;i<m;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            row.push_back(num);
        }
        grid.push_back(row);
    }
    
    Solution *solution=new Solution();
    cout<<solution->minPathSum(grid);
    
    return 0;
}
