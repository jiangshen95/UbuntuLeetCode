/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        
        int m = matrix.size();
        //int n = matrix[0].size();
        
        int result = 0;
        
         for(int i=0;i<m;i++){
             for(int j=i;j<m;j++){
                 result = max(result, getSquare(matrix, i, j));
             }
         }
         
         return result;
    }
    
    int getSquare(vector<vector<char> >& matrix, int begin, int end){
        
        //int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> v(n, 0);
        
        for(int i=begin;i<=end;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1') v[j] ++;
            }
        }
        
        int count = 0;
        int k = end - begin + 1;
        for(int i=0;i<n;i++){
            if(v[i] == k) count ++;
            else count = 0;
            if(count == k) return k * k;
        }
        
        return 0;
    }
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    vector<vector<char> > matrix;
    for(int i=0;i<m;i++){
        vector<char> raw;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            raw.push_back(ch);
        }
        matrix.push_back(raw);
    }
    
    Solution *solution = new Solution();
    cout<<solution->maximalSquare(matrix);
    
    return 0;
}
