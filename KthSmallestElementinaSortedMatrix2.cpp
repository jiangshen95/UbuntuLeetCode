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
			int count = 0;
			for(int i = 0; i < n; i++) {
				count += binarySearch(matrix[i], 0, n - 1, mid);
			} 
			
			cout<<"count: "<<count<<"  "<<"mid: "<<mid<<endl; 
			
			if(count < k) low = mid + 1;
			else high = mid;
        	
		}
		
		return low;
		
		
        
    }
    
    int binarySearch(vector<int> nums, int l, int r, int v) {
    	while(l <= r) {
    		int mid = (l + r) / 2;
    		if(v >= nums[mid]) l = mid + 1;
    		else r = mid - 1;
		}
		return l;
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
