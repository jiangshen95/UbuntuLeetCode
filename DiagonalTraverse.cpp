#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
    	if(matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        
        for(int k = 0; k <= (m + n - 2); k++) {
        	if(k % 2 == 0) {
        		for(int i = min(k, m - 1); i >= max(0, k - n + 1); i--) {
//        			if(k - i >= n) continue;
        			result.push_back(matrix[i][k - i]);
				}
			}else {
				for(int i = max(0, k - n + 1); i <= min(k, m - 1); i++) {
//					if(k - i >= n) continue;
					result.push_back(matrix[i][k - i]);
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
