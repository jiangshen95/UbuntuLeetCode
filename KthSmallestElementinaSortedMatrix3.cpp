#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        
        while(low < high) {
        	
        	int mid = (low + high) / 2;
			int count = search_less_equal(matrix, mid); 
			
			if(count < k) low = mid + 1;
			else high = mid;
        	
		}
		
		return low;
    }
    
    int search_less_equal(vector<vector<int> > matrix, int target) {
    	int n = matrix.size();
    	int i = n - 1, j = 0, count = 0;
    	while(i >= 0 && j < n) {
    		if(matrix[i][j] <= target) {
    			count += i + 1;
    			j++;
			}else {
				i--;
			}
		}
		return count;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<vector<int> > matrix;
	for(int i = 0; i < n; i++) {
		vector<int> raw;
		for(int j = 0; j < n; j++) {
			int item;
			cin>>item;
			raw.push_back(item);
		}
		matrix.push_back(raw);
	}
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	cout<<solution->kthSmallest(matrix, k);
	
	return 0;
	
}
