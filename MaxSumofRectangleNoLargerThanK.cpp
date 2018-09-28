/*
** Time Limit Exceeded
*/
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
        
        int s = 0;
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		s += matrix[i][j];
			}
		}
        
        return sumSubmatrix(matrix, 0, 0, m - 1, n - 1, s, k, INT_MIN);
    }
    
    int sumSubmatrix(vector<vector<int> > matrix, int a, int b, int c, int d, int s, int k, int max_sub) {
    	
    	if(a > c || b > d) return max_sub;
    	
    	if(s == k) return s;
    	
    	if(s <= k) max_sub = max(max_sub, s);
    	
    	int r = 0;
    	for(int i = b; i <= d; i++) {
    		r += matrix[a][i];
		}
		max_sub = max(max_sub, sumSubmatrix(matrix, a + 1, b, c, d, s - r, k, max_sub));
		
		r = 0;
		for(int i = b; i <= d; i++) {
			r += matrix[c][i];
		}
		max_sub = max(max_sub, sumSubmatrix(matrix, a, b, c - 1, d, s - r, k, max_sub));
		
		r = 0;
		for(int i = a; i <= c; i++) {
			r += matrix[i][b];
		}
		max_sub = max(max_sub, sumSubmatrix(matrix, a ,b + 1, c, d, s - r, k, max_sub));
		
		r = 0;
		for(int i = a; i <= c; i++) {
			r += matrix[i][d];
		}
		max_sub  = max(max_sub, sumSubmatrix(matrix, a, b, c, d - 1, s - r, k, max_sub));
		
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
