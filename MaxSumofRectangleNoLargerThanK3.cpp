#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        
        int max_sum = INT_MIN;
        
        for(int i = 0; i < n; i++) {
        	vector<int> sum(m, 0);
        	for(int j = i; j < n; j++) {
        		for(int x = 0; x < m; x++) {
        			sum[x] += matrix[x][j]; 
				}
				
				int curSum = 0, curMax = INT_MIN;
				set<int> s;
				s.insert(0);
				
				for(auto a : sum) {
					curSum += a;
					auto it = s.lower_bound(curSum - k);
					if(it != s.end()) curMax = max(curMax, curSum - *it);
					s.insert(curSum);
				}
				
				max_sum = max(max_sum, curMax);
				
			}
		}
		
		return max_sum;
        
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
