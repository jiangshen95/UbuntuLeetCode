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
        
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                vector<char> row=matrixLineAnd(matrix, i, j, n);
                int m=getLineMax(row)*(j-i+1);
                if(m>max){
                    max=m;
                }
            }
        }
        
        return max;
        
    }
    
    int getLineMax(vector<char>& row){
        int curr=0;
        int max=0;
        for(int i=0;i<row.size();i++){
            if(i==0){
                curr= row[i]=='1' ? 1 : 0;
                max=curr;
            }else{
                if(row[i]=='1'){
                    curr+=1;
                    max = curr>max?curr:max;
                }else{
                    curr=0;
                }
            }
        }
        
        cout<<"max: "<<max<<endl;
        
        return max;
    }
    
    vector<char> matrixLineAnd(vector<vector<char> >& matrix, int begin, int end, int n){
        vector<char> row(n, '1');
        for(int i=begin;i<=end;i++){
            for(int j=0;j<n;j++){
                row[j] = row[j]=='1'&&matrix[i][j]=='1' ? '1' : '0';
            }
        }
        
        return row;
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
