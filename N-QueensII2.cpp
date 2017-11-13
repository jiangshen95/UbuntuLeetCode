#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    
    vector<int> stack_y;
    vector<int> stack_sumxy;
    vector<int> stack_difxy;
    
    int totalNQueens(int n) {
        
        int total=0;
        solveNQueens(total,0,n);
        
        return total;
    }

    void solveNQueens(int& total, int row,int n){
        for(int i=0;i<n;i++){
            int j;
            for(j=0;j<stack_y.size();j++){
                if(i==stack_y[j]){
                    break;
                }
            }
            if(j!=stack_y.size()){
                continue;
            }
            
            for(j=0;j<stack_sumxy.size();j++){
                if(row+i==stack_sumxy[j]){
                    break;
                }
            }
            if(j!=stack_sumxy.size()){
                continue;
            }
            
            for(j=0;j<stack_difxy.size();j++){
                if(row-i==stack_difxy[j]){
                    break;
                }
            }
            if(j!=stack_difxy.size()){
                continue;
            }
            
            stack_y.push_back(i);
            stack_difxy.push_back(row-i);
            stack_sumxy.push_back(row+i);
            
            if(row==n-1){
                total++;
            }
            else{
                solveNQueens(total,row+1,n);
            }
            
            stack_y.pop_back();
            stack_difxy.pop_back();
            stack_sumxy.pop_back();
            
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
