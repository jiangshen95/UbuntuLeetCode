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
        
        int rl=0,rr=n-1;
        int ch=0,cl=m-1;
        
        while(rl<=rr&&ch<=cl){
            for(int i=rl;i<=rr;i++){
                result.push_back(matrix[ch][i]);
            }
            for(int i=ch+1;i<=cl;i++){
                result.push_back(matrix[i][rr]);
            }
            if(rl<rr&&ch<cl){
                for(int i=rr-1;i>=rl;i--){
                    result.push_back(matrix[cl][i]);
                }
                for(int i=cl-1;i>ch;i--){
                    result.push_back(matrix[i][rl]);
                }
            }
            rl++;
            rr--;
            ch++;
            cl--;
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
