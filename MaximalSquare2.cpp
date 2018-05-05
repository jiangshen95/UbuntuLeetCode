#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        
        int result = 0;
        
         for(int i=0;i<m;i++){
             vector<int> v(n, 0);
             for(int j=i;j<m;j++){
                 for(int k=0;k<n;k++){
                     if(matrix[j][k] == '1') v[k] ++;
                 }
                 result = max(result, getSquare(v, j - i + 1));
             }
         }
         
         return result;
    }
    
    int getSquare(vector<int>& v, int k){
        
        int count = 0;
        for(int i=0;i<v.size();i++){
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
