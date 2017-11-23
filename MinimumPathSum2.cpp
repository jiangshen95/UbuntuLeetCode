#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int temp[m];
        temp[0]=grid[0][0];
        
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(i==0&&j==0) continue;
                if(i==0){
                    temp[i]=temp[i]+grid[i][j];
                }else if(j==0){
                    temp[i]=temp[i-1]+grid[i][j];
                }else{
                    temp[i] = (temp[i-1]>temp[i] ? temp[i] : temp[i-1])+grid[i][j];
                }
            }
        }
        
        return temp[m-1];
        
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
