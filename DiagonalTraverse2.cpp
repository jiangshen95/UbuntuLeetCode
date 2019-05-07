#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
    	if(matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        
        int r = 0, c = 0, k = 0;
        vector<vector<int> > dirs = {{-1, 1}, {1, -1}};
        for(int i = 0; i < m * n; i++) {
        	result.push_back(matrix[r][c]);
        	r += dirs[k][0];
        	c += dirs[k][1];
        	
        	if(r >= m) {
        		r = m - 1;
        		c += 2;
        		k = 1 - k;
			}
			if(c >= n) {
				c = n - 1;
				r += 2;
				k = 1 - k;
			}
			if(r < 0) {
				r = 0;
				k = 1 - k;
			}
			if(c < 0) {
				c = 0;
				k = 1 - k;
			}
		}
		return result;
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
	vector<int> result = solution->findDiagonalOrder(matrix);
	
	for(int num : result) cout<<num<<" ";
	
	return 0;
}
