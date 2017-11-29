/*
 * O(m+n)
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        
        int m=matrix.size(), n=matrix[0].size();
        
        int row[m], clumn[n];
        for(int i=0;i<m;i++) row[i]=0;
        for(int i=0;i<n;i++) clumn[i]=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]++;
                    clumn[j]++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            if(row[i]){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int j=0;j<n;j++){
            if(clumn[j]){
                for(int i=0;i<m;i++){
                    matrix[i][j]=0;
                }
            }
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
