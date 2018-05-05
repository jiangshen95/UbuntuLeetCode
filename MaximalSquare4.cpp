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
        vector<vector<int> > dp(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
                else{
                    if(matrix[i][j] == '0') dp[i][j] = 0;
                    else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                result = max(result, dp[i][j]);
            }
        }
        
        return result * result;
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
