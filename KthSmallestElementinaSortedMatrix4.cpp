#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        
        int n = matrix.size();
        auto cmp = [&matrix](pair<int, int> a, pair<int, int> b) {
        	return matrix[a.first][a.second] > matrix[b.first][b.second];
		};
		
		priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> q(cmp);
		q.emplace(0, 0);
		for(int i = 0; i < k - 1; i++) {
			pair<int, int> index_pair = q.top();
			q.pop();
			if(index_pair.first == 0 && index_pair.second + 1 < n) q.emplace(index_pair.first, index_pair.second + 1);
			if(index_pair.first + 1 < n) q.emplace(index_pair.first + 1, index_pair.second);
		}
		
		return matrix[q.top().first][q.top().second];
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
