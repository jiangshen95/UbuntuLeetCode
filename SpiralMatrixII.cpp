#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        
        vector<vector<int> > matrix(n, vector<int>(n));
        int count=1;
        
        int l=0, r=n-1;
        while(l<=r){
            for(int i=l;i<=r;i++){
                matrix[l][i]=count++;
            }
            for(int i=l+1;i<=r;i++){
                matrix[i][r]=count++;
            }
            for(int i=r-1;i>=l;i--){
                matrix[r][i]=count++;
            }
            for(int i=r-1;i>l;i--){
                matrix[i][l]=count++;
            }
            
            l++;
            r--;
        }
        
        return matrix;
        
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<vector<int> > matrix;
    Solution *solution=new Solution();
    matrix=solution->generateMatrix(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    return 0;
}
