#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        
        int m=matrix.size(), n=matrix[0].size();
        bool col0=false;
        
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) col0=true;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0||matrix[0][j]==0) matrix[i][j]=0;
            }
            if(col0) matrix[i][0]=0;
        }
        
    }
};

int main(){
    int m, n;
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
    
    Solution *solution=new Solution();
    solution->setZeroes(matrix);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

