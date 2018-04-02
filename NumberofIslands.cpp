#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int number = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    number ++;
                    searchIsland(grid, i, j);
                }
            }
        }
        
        return number;
    }
    
    void searchIsland(vector<vector<char> >& grid, int i, int j){
        grid[i][j] = 0;
        if(j<grid[0].size()-1 && grid[i][j+1] == '1') searchIsland(grid, i, j+1);
        if(j>0 && grid[i][j-1] == '1') searchIsland(grid, i, j-1);
        if(i<grid.size()-1 && grid[i+1][j] == '1') searchIsland(grid, i+1, j);
        if(i>0 && grid[i-1][j] == '1') searchIsland(grid, i-1, j);
    }
    
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    vector<vector<char> > grid;
    for(int i=0;i<m;i++){
        vector<char> raw;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            raw.push_back(ch);
        }
        grid.push_back(raw);
    }
    
    Solution *solution = new Solution();
    cout<<solution->numIslands(grid);
    
}
