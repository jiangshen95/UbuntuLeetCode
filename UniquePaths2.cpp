#include<iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        /*int matrix[m][n];
        matrix[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                matrix[i][j]=  (j-1>=0 ? matrix[i][j-1] : 0) + (i-1>=0 ? matrix[i-1][j] : 0);
            }
        }
        
        return matrix[m-1][n-1];*/
        if(m>n) uniquePaths(n, m);
        int cur[m];
        for(int i=0;i<m;i++) cur[i]=1;
        for(int j=1;j<n;j++){
            for(int i=1;i<m;i++){
                cur[i]+=cur[i-1];
            }
        }
        
        return cur[m-1];
        
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    Solution *solution = new Solution();
    cout<<solution->uniquePaths(m, n);
    
    return 0;
}

