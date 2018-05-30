#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
		int n = matrix[0].size();
		if(n == 0) return false;
		
		int col = n - 1;
		int raw = 0;
		while(col >= 0 && raw < m) {
			if(matrix[raw][col] == target) return true;
			else if(matrix[raw][col] < target) raw ++;
			else col --;
		}
		
		return false;
    }
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<vector<int> > matrix;
	for(int i=0;i<m;i++) {
		vector<int> raw;
		for(int j=0;j<n;j++) {
			int num;
			cin>>num;
			raw.push_back(num);
		}
		matrix.push_back(raw);
	}
	
	int target;
	cin>>target;
	
	Solution *solution = new Solution();
	solution->searchMatrix(matrix, target) ? cout<<"True" : cout<<"False";
	
	return 0;
	
}
