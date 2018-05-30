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
		
		for(int i=0;i<m;i++) {
			int begin = 0;
			int end = n - 1;
			if(matrix[i][begin] > target || matrix[i][end] < target) continue;
			while(begin < end) {
				int mid = (begin + end) / 2;
				if(matrix[i][mid] < target) begin = mid + 1;
				else end = mid;
			}
			if(matrix[i][begin] == target) return true;
		}
		
		return false;
		
//		int begin1 = 0, begin2 = 0;
//		int end1 = m - 1, end2 = n - 1;
//		int mid1, mid2;
//		
//		while(begin1 < end1 || begin2 < end2) {
//			mid1 = (begin1 + end1) / 2;
//			mid2 = (begin2 + end2) / 2;
//			if(matrix[mid1][mid2] < target) {
//				if(begin1 < end1) begin1 = mid1 + 1;
//				if(begin2 < end2) begin2 = mid2 + 1;
//			}else {
//				end1 = mid1;
//				end2 = mid2;
//			}
//		}
//		
//		return matrix[begin1][begin2] == target;
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
