#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        int max=0;
        
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        for(int i=0;i<m;i++){
            int curr_left=0, curr_right=n;
            for(int j=0;j<n;j++){
                height[j]=matrix[i][j]=='0' ? 0 : (1+height[j]);
            }
            
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') left[j]=left[j]>curr_left?left[j]:curr_left;
                else{
                    left[j]=0;
                    curr_left=j+1;
                }
            }
            
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1') right[j]=right[j]<curr_right?right[j]:curr_right;
                else{
                    right[j]=n;
                    curr_right=j;
                }
            }
            
            for(int j=0;j<n;j++){
                if((right[j]-left[j])*height[j]>max){
                    max=(right[j]-left[j])*height[j];
                }
            }
        }
        
        return max;
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    vector<vector<char> > matrix;
    for(int i=0;i<m;i++){
        vector<char> row;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            row.push_back(ch);
        }
        matrix.push_back(row);
    }
    
    Solution *solution=new Solution();
    cout<<solution->maximalRectangle(matrix);
    
    return 0;
}
