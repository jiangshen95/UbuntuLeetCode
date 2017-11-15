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
        
        for(int i=0;i<(m/2)+(m%2)&&i<(n/2)+(n%2);i++){
            
            for(int j=i;j<n-i-1;j++){
                cout<<"1----"<<matrix[i][j]<<endl;
                result.push_back(matrix[i][j]);
            }
            if(i==m-i-1){
                result.push_back(matrix[i][n-i-1]);
            }
            if(n-i-1>=0){
                for(int j=i;j<m-i-1;j++){
                    cout<<"2----"<<matrix[j][n-i-1]<<endl;
                    result.push_back(matrix[j][n-i-1]);
                }
                if(i==n-i-1&&i!=m-i-1){
                    result.push_back(matrix[m-i-1][i]);
                }
            }
            if(m-i-1>=0&&i!=m-i-1){
                for(int j=n-i-1;j>i;j--){
                    cout<<"3----"<<matrix[m-i-1][j]<<endl;
                    result.push_back(matrix[m-i-1][j]);
                }
            }
            if(i!=n-i-1){
                for(int j=m-i-1;j>i;j--){
                    cout<<"4----"<<matrix[j][i]<<endl;
                    result.push_back(matrix[j][i]);
                }
            }
            
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
