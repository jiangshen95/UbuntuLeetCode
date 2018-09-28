#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        
        vector<vector<int> > sum(m, vector<int>(n));
        
        int max_sub = INT_MIN;
        
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		
        		if(i == 0 && j == 0) sum[i][j] = matrix[i][j];
        		else if(i == 0) sum[i][j] = sum[i][j - 1] + matrix[i][j];
        		else if(j == 0) sum[i][j] = sum[i - 1][j] + matrix[i][j];
        		else sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + matrix[i][j] - sum[i - 1][j - 1];
        		
        		cout<<sum[i][j]<<endl;
        		
        		for(int x = 0; x <= i; x++) {
        			for(int y = 0; y <= j; y++) {
        				int d = sum[i][j];
        				if(x > 0) d -= sum[x - 1][j];
        				if(y > 0) d -= sum[i][y - 1];
        				if(x > 0 && y > 0) d +=  sum[x - 1][y - 1];
						
						if(d == k) return k;
						if(d <= k) max_sub = max(max_sub, d); 
					}
				}

			}
		}
		
		return max_sub;
        
    }
    
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<vector<int> > matrix;
	for(int i = 0; i < m; i++) {
		vector<int> row;
		for(int j = 0; j < n; j++) {
			int num;
			cin>>num;
			row.push_back(num);
		}
		matrix.push_back(row);
	}
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	cout<<solution->maxSumSubmatrix(matrix, k);
	
	return 0;
	
}
