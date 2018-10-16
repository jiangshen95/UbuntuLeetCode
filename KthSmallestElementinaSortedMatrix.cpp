#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        
        int n = matrix.size();
        priority_queue<int> q;
        
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) {
        		q.emplace(matrix[i][j]);
        		if(q.size() > k) {
        			q.pop();
				} 
			}
		}
		
		return q.top();
        
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
