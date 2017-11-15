#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        
        vector<int> result;
        
        int m=matrix.size();
        if(m<=0){
            return result;
        }
        int n=matrix[0].size();
        bool has_add[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                has_add[i][j]=false;
            }
        }
        
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        
        int x=0;
        int y=0;
        int di=0;
        for(int i=0;i<m*n;i++){
            cout<<"-----"<<matrix[x][y]<<endl;
            result.push_back(matrix[x][y]);
            has_add[x][y]=true;
            if(x+dr[di]>=m || x+dr[di]<0 || y+dc[di]<0 || y+dc[di]>=n || has_add[x+dr[di]][y+dc[di]]){
                di++;
            }
            di = di>3 ? di-4 : di;
            
            x+=dr[di];
            y+=dc[di];
            
        }
        
        return result;
    }
};

int main(){
    
    int m,n;
    cin>>m>>n;
    
    vector<vector<int> > matrix;
    for(int i=0;i<m;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    
    vector<int> result;
    Solution *solution=new Solution();
    result=solution->spiralOrder(matrix);
    
    for(int i=0;i<m*n;i++){
        cout<<result[i]<<"  ";
    }
    
    return 0;
}
