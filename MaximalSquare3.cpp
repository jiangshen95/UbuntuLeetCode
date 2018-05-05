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
        vector<vector<int> > sum(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int t = matrix[i][j] - '0';
                if(i > 0) t += sum[i-1][j];
                if(j > 0) t += sum[i][j-1];
                if(i > 0 && j > 0) t -= sum[i-1][j-1];
                sum[i][j] = t;
                
                for(int k=1;k<=min(i, j) + 1;k++){
                    int d = sum[i][j];
                    if(i - k >= 0) d -= sum[i-k][j];
                    if(j - k >= 0) d -= sum[i][j-k];
                    if(i - k >= 0 && j - k >= 0) d += sum[i - k][j - k];
                    if(d == k * k) result = max(result, d);
                }
            }
        }
        
        return result;
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
