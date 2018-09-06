#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
    	
    	int m = matrix.size();
    	if(m == 0) return 0;
    	int n = matrix[0].size();
    	
    	vector<vector<int> > cache(m, vector<int>(n, 0));
        
        int maxLen = 1;
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		maxLen = max(getIncreasingPath(cache, matrix, i, j), maxLen);
			}
		}
		
		return maxLen;
        
    }
    
    int getIncreasingPath(vector<vector<int> >& cache, vector<vector<int> >& matrix, int x, int y) {
    	
    	if(cache[x][y] > 0) return cache[x][y];
    	
    	int m = matrix.size();
    	int n = matrix[0].size();
    	
    	int maxLen = 1;
    	
    	vector<vector<int> > direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    	for(int i = 0; i < direction.size(); i++) {
    		if(x + direction[i][0] >= 0 && x + direction[i][0] < m && y + direction[i][1] >= 0 && y + direction[i][1] < n 
				&& matrix[x + direction[i][0]][y + direction[i][1]] > matrix[x][y]) {
    			maxLen = max(getIncreasingPath(cache, matrix, x + direction[i][0], y + direction[i][1]) + 1, maxLen);
			}
		}
		
		cache[x][y] = maxLen;
		return maxLen; 
    	
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
	
	Solution *solution = new Solution();
	cout<<solution->longestIncreasingPath(matrix);
	
	return 0;
	
}
