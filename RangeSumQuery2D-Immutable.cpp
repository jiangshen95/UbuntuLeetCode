#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
private:
	vector<vector<int> > sums;
public:
    NumMatrix(vector<vector<int> > matrix) {
    	int m = matrix.size();
    	if(m == 0) return;
    	int n = matrix[0].size();
    	sums = vector<vector<int> >(m, vector<int>(n));
        for(int i = 0;i < matrix.size();i++) {
        	int sum = 0;
        	for(int j = 0;j < matrix[i].size();j++) {
        		sum += matrix[i][j];
        		if(i == 0) sums[i][j] = sum;
        		else sums[i][j] = sums[i - 1][j] + sum;
			}
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2][col2] - (col1 > 0 ? sums[row2][col1 - 1] : 0) - (row1 > 0 ? sums[row1 - 1][col2] : 0) + (col1 > 0 && row1 > 0 ? sums[row1 - 1][col1 - 1] : 0);
    }
};

int main() {
	vector<vector<int> > matrix = {
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5}
	};
	NumMatrix *c = new NumMatrix(matrix);
	cout<<c->sumRegion(2, 1, 4 ,3)<<endl;
	cout<<c->sumRegion(1, 1, 2, 2)<<endl;
	cout<<c->sumRegion(1, 2, 2, 4)<<endl;
	
	return 0;
}
