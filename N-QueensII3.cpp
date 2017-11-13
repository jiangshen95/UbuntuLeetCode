
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    
    int totalNQueens(int n) {
        
        vector<bool> col(n,true);
        vector<bool> sum_xy(n*2,true);
        vector<bool> dif_xy(n*2,true);
        
        int total=0;
        solveNQueens(total,0,n,col,sum_xy,dif_xy);
        
        return total;
    }

    void solveNQueens(int& total, int row,int n,vector<bool>& col,vector<bool>& sum_xy,vector<bool>& dif_xy){
        for(int i=0;i<n;i++){
            
            if(col[i]&&sum_xy[row+i]&&dif_xy[row-i+n]){
                col[i]=false;
                sum_xy[row+i]=false;
                dif_xy[row-i+n]=false;
                
                if(row==n-1){
                    total++;
                }
                else{
                    solveNQueens(total,row+1,n,col,sum_xy,dif_xy);
                }
                
                col[i]=true;
                sum_xy[row+i]=true;
                dif_xy[row-i+n]=true;
            }
        }
    }

};

int main(){

    int n;
    cin>>n;

    Solution *solution=new Solution();
    cout<<solution->totalNQueens(n);

    return 0;

}
