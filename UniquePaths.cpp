/*
 * Time Limit Exceeded
*/
#include<iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int count=0;
        getAllPaths(0, 0, m, n, count);
        return count;
    }
    
    void getAllPaths(int x, int y, int m, int n, int& count){
        if(x==m-1&&y==n-1){
            count++;
        }else if(x<m&&y<n){
            getAllPaths(x, y+1, m, n, count);
            getAllPaths(x+1, y, m, n, count);
        }
        
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    Solution *solution = new Solution();
    cout<<solution->uniquePaths(m, n);
    
    return 0;
}
