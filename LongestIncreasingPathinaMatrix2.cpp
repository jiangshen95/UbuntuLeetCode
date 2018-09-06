#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
    	
    	int m = matrix.size();
    	if(m == 0) return 0;
    	int n = matrix[0].size();
    	
    	int count = m * n, ans = 0;
    	while(count > 0) {
    		vector<pair<int, int> > remove;
    		for(int i = 0; i < m; i++) {
    			for(int j = 0; j < n; j++) {
    				if(matrix[i][j] == INT_MIN) continue;
    				bool up = (i == 0 || matrix[i][j] >= matrix[i - 1][j]);
    				bool down = (i == m - 1 || matrix[i][j] >= matrix[i + 1][j]);
    				bool left = (j == 0 || matrix[i][j] >= matrix[i][j - 1]);
    				bool right = (j == n - 1 || matrix[i][j] >= matrix[i][j + 1]);
    				
    				if(up && down && left && right) remove.push_back(make_pair(i, j));
				}
			}
			
			for(auto p : remove) {
				matrix[p.first][p.second] = INT_MIN;
				count--;
			}
			
			ans++;
		}
		
		return ans;
        
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
