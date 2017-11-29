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
        
        int l=0, r=m*n-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(matrix[mid/n][mid%n]>target){
                r=mid-1;
            }else if(matrix[mid/n][mid%n]<target){
                l=mid+1;
            }else{
                break;
            }
        }
        
        return matrix[mid/n][mid%n]==target;
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
