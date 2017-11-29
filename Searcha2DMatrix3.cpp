#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        if(n==0) return false;
        
        int i=0, j=n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]>target){
                j--;
            }else if(matrix[i][j]<target){
                i++;
                j=n-1;
            }else{
                return true;
            }
        }
        
        return false;
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
    
    int target;
    cin>>target;
    
    Solution *solution=new Solution();
    if(solution->searchMatrix(matrix, target)){
        cout<<"True";
    }else cout<<"False";
    
    return 0;
}
