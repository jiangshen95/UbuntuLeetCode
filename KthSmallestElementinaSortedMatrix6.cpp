#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        
        if(k == 1) return matrix.front().front();
        
        int n = matrix.size();
        int start = max(k - n * n + n - 1, 0);
        k -= n * n - (n - start) * (n - start);
        vector<int> indices(min(start + k, n) - start, 0);
        //for(int i = 0; i < n; i++) indices[i] = i;
        iota(indices.begin(), indices.end(), start);
        vector<int> results = biselect(matrix, indices, k, k);
        
        return results[0];
        
    }
private:
	vector<int> biselect(vector<vector<int> >& matrix, vector<int>& indices, int k1, int k2) {
		int n = indices.size();
		for(int i = 0; i < n; i++) cout<<indices[i]<<"  ";
		cout<<endl;
		if(n <= 2) {
			return biselectNative(matrix, indices, k1, k2);
		}
		
		vector<int> indices_;
		for(int i = 0; i < n; i += 2) {
			indices_.push_back(indices[i]);
		}
		if(n % 2 == 0) {
			indices_.push_back(indices.back());
		}
		
		//int k1_ = n % 2 == 0 ? n + 1 + k1 / 4 : (k1 + 2 * n + 1) / 4;
		int k1_ = n % 2 == 0 ? n + 1 + (k1 + 1) / 4 : (k1 + 2 * n) / 4 + 1;
		int k2_ = (k2 + 3) / 4;
		
		cout<<k1_<<"  "<<k2_<<endl;
		
		vector<int> xs = biselect(matrix, indices_, k1_, k2_);
		int a = xs[0], b = xs[1];
		cout<<"a: "<<a<<"  b: "<<b<<endl;
		int ja = n, jb = n;
//		int ra_less = 0, rb_more = 0;
		vector<int> L;
		
		int ra_less = 0, rb_less = 0;
		for(int i = 0; i < n; i++) {
			while(ja > 0 && matrix[indices[i]][indices[ja - 1]] >= a) ja--;
			while(jb > 0 && matrix[indices[i]][indices[jb - 1]] >= b) jb--;
			ra_less += ja;
			rb_less += jb;
			for(int j = jb; j < ja; j++) L.push_back(matrix[indices[i]][indices[j]]);
		}
		
		for(int i = 0; i < L.size(); i++) cout<<L[i]<<"  ";
		cout<<endl;
		
		int x = k1 - 1 < rb_less ? b : (k1 - 1 < ra_less ? pick(L, k1 - rb_less) : a);
		int y = k2 - 1 < rb_less ? b : (k2 - 1 < ra_less ? pick(L, k2 - rb_less) : a);
		
//		for(int i = 0; i < n; i++) {
//			while(ja > 0 && matrix[indices[i]][indices[ja - 1]] >= a) ja--;
//			while(jb > 0 && matrix[indices[i]][indices[jb - 1]] > b) jb--;
//			ra_less += ja;
//			rb_more += n - jb;
//			for(int j = jb; j < ja; j++) L.push_back(matrix[indices[i]][indices[j]]);
//		}
//		
//		for(int i = 0; i < L.size(); i++) cout<<L[i]<<"  ";
//		cout<<endl;
//		
//		int x = ra_less <= k1 - 1 ? a : (k1 + rb_more - n * n <= 0 ? b : pick(L, k1 + rb_more - n * n));
//		int y = ra_less <= k2 - 1 ? a : (k2 + rb_more - n * n <= 0 ? b : pick(L, k2 + rb_more - n * n));
		
		return vector<int>{x, y};
	}
	
	int pick(vector<int> L, int k) {
		cout<<k<<endl;
		vector<int>::iterator nth = next(L.begin(), k - 1);
		nth_element(L.begin(), nth, L.end());
		return *nth;
	}
	
	vector<int> biselectNative(vector<vector<int> >& matrix, vector<int>& indices, int k1, int k2) {
		vector<int> allElements;
		for(int r : indices) {
			for(int c :indices) {
				allElements.push_back(matrix[r][c]);
			}
		}
		sort(allElements.begin(), allElements.end());
		vector<int> result;
		result.push_back(allElements[k1 - 1]);
		result.push_back(allElements[k2 - 1]);
		
		return result;
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
