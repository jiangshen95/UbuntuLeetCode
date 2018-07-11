#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());
        
        int len = citations.size();
        
        for(int i=0;i<citations.size();i++) {
        	if(len <= citations[i]) return len;
        	else len --;
		}
		
		return 0;
        
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> citations;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		citations.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->hIndex(citations);
	
	return 0;
	
}
