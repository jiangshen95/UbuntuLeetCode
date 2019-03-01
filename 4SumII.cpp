#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        int n = A.size();
        unordered_map<int, int> m1, m2;
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) {
        		m1[A[i] + B[j]]++;
        		m2[C[i] + D[j]]++;
			}
		}

		for(auto it : m1) {
			if(m2.find(-it.first) != m2.end()) count += it.second * m2[-it.first];
		}
		
		
		return count;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> A;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		A.push_back(num);
	}
	
	vector<int> B;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		B.push_back(num);
	}
	
	vector<int> C;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		C.push_back(num);
	}
	
	vector<int> D;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		D.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->fourSumCount(A, B, C, D);
	
	return 0;
}
