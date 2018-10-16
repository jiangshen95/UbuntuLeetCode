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
        vector<int> indices(n, 0);
        //for(int i = 0; i < n; i++) indices[i] = i;
        iota(indices.begin(), indices.end(), 0);
        vector<int> ks{k - 1, k - 1};
        vector<int> results = biselect(matrix, indices, ks);
        
        return results[0];
        
    }
private:
	vector<int> biselect (vector<vector<int> >& matrix, vector<int>& indices, vector<int>& ks) {
		int n = indices.size();
		if(n == 2) {
			return biselectNative(matrix, indices, ks);
		}
		
		vector<int> indices_;
		for(int i = 0; i < n; i += 2) {
			indices_.push_back(indices[i]);
		}
		if(n % 2 == 0) {
			indices_.push_back(indices.back());
		}
		
		vector<int> ks_{ks[0] / 4, 0};
		if(n % 2 == 0) {
			ks_[1] = ks[1] / 4 + n + 1;
		}else {
			ks_[1] = (ks[1] + 2 * n + 1) / 4;
		}
		
		vector<int> xs_ = biselect(matrix, indices_, ks_);
		
		vector<int> numbersOfElementsLessThanX{0, 0};
		vector<int> elementsBetween;
		
		vector<int> cols = {n, n};
		
		for(int row = 0; row < n; row++) {
			int row_indice = indices[row];
			for(int i = 0; i < 2; i++) {
				while((cols[i] > 0) && (matrix[row_indice][indices[cols[i] - 1]]) >= xs_[i]) --cols[i];
				numbersOfElementsLessThanX[i] += cols[i];
			}
			for(int col = cols[0]; col < cols[1]; col++) {
				elementsBetween.push_back(matrix[row_indice][indices[col]]);
			}
		}
		
		vector<int> xs(2);
		for(int i = 0; i < 2; i++) {
			int k = ks[i];
			if(k < numbersOfElementsLessThanX[0]) {
				xs[i] = xs_[0];
			}else if(k < numbersOfElementsLessThanX[1]) {
				int offset = k - numbersOfElementsLessThanX[0];
				vector<int>::iterator nth = next(elementsBetween.begin(), offset);
				nth_element(elementsBetween.begin(), nth, elementsBetween.end());
				xs[i] = (*nth); 
			}else {
				xs[i] = xs_[1];
			}
		}
		
		return xs;
	}
	
	vector<int> biselectNative(vector<vector<int> >& matrix, vector<int>& indices, vector<int>& ks) {
		vector<int> allelements;
		for(int r : indices) {
			for(int c :indices) {
				allelements.push_back(matrix[r][c]);
			}
		}
		sort(allelements.begin(), allelements.end());
		vector<int> result;
		for(int i = 0; i <= 1; i++) {
			result.push_back(allelements[ks[i]]);
		}
		
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
