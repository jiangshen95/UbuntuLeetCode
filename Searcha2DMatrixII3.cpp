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
		
		return searchMatrix(matrix, 0, m - 1, 0, n - 1, target, m, n);
    }
    
    bool searchMatrix(vector<vector<int> >& matrix, int begin1, int end1, int begin2, int end2, int target, int m, int n) {
    	
    	if(begin1 > end1 || begin2 > end2 || end1 >= m || end2 >= n || begin1 < 0 || begin2 < 0) return false;
    	if(begin1 ==  end1 && begin2 == end2) return matrix[begin1][begin2] == target;
    	
    	int mid1 = (begin1 + end1) / 2;
    	int mid2 = (begin2 + end2) / 2;
    	
    	if(matrix[mid1][mid2] < target) return searchMatrix(matrix, mid1 + 1, end1, mid2 + 1, end2, target, m, n) || searchMatrix(matrix, mid1 + 1, end1, begin2, mid2, target, m, n) ||
    											searchMatrix(matrix, begin1, mid1, mid2 + 1, end2, target, m, n);
    	else if(matrix[mid1][mid2] > target) return searchMatrix(matrix, begin1, mid1 - 1, begin2, mid2 - 1, target, m, n) || searchMatrix(matrix, begin1, mid1 - 1, mid2, end2, target, m, n) ||
    											searchMatrix(matrix, mid1, end1, begin2, mid2 - 1, target, m, n);
    	else return true;	
    	
//    	if(matrix[mid1][mid2] < target) return searchMatrix(matrix, mid1 + 1, end1, mid2 + 1, end2, target, m, n) || searchMatrix(matrix, mid1 + 1, end1, begin2, end2, target, m, n) ||
//    											searchMatrix(matrix, begin1, end1, mid2 + 1, end2, target, m, n);
//    	else if(matrix[mid1][mid2] > target) return searchMatrix(matrix, begin1, mid1 - 1, begin2, mid1 - 1, target, m, n) || searchMatrix(matrix, begin1, mid1 - 1, begin2, end2, target, m, n) ||
//    											searchMatrix(matrix, begin1, end1, begin2, mid2 - 1, target, m, n);
//    	else return true;
    	
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
