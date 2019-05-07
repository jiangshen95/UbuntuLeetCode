#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
    	if(matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        
        int r = 0, c = 0;
        for(int i = 0; i < m * n; i++) {
        	result.push_back(matrix[r][c]);
        	if((r + c) % 2 == 0) {
        		if(c == n - 1) r++;
        		else if(r == 0) c++;
        		else {
        			r--;
        			c++;
				}
			}else {
				if(r == m - 1) c++;
				else if(c == 0) r++;
				else {
					r++;
					c--;
				}
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
