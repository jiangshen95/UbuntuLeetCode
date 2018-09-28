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
        		vector<int> allsums(m + 1, 0);
        		for(int x = 0; x < m; x++) {
        			sum[x] += matrix[x][j]; 
        			allsums[x + 1] = allsums[x] + sum[x];
				}
				
				max_sum = max(max_sum, mergesort(allsums, 0, m, k));
				
				//cout<<max_sum<<endl;
				
				if(max_sum == k) return k;
				
			}
		}
		
		return max_sum;
        
    }
    
    int mergesort(vector<int>& allsums, int left, int right, int k) {
    	
    	if(left >= right) return INT_MIN;
    	
    	int mid = left + (right - left) / 2;
    	
    	int max_sum = mergesort(allsums, left, mid, k);
    	if(max_sum == k) return k;
    	max_sum = max(max_sum, mergesort(allsums, mid + 1, right, k));
    	if(max_sum == k) return k;
    	
    	vector<int> cache;
    	for(int i = left, j = mid + 1, p = mid + 1; i <= mid; i++) {
    		
    		while(j <= right && allsums[j] - allsums[i] <= k) j++;
    		if(j > mid + 1) {
    			cout<<allsums[j - 1] - allsums[i]<<endl;
    			max_sum = max(max_sum, allsums[j - 1] - allsums[i]);
    			if(max_sum == k) return k;
			}
			
			while(p <= right && allsums[p] < allsums[i]) cache.push_back(allsums[p++]);
			
			cache.push_back(allsums[i]);
		}
		
		for(int i = 0; i < cache.size(); i++) allsums[i + left] = cache[i];
		
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
