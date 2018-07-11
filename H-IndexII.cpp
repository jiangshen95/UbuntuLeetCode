#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int len = citations.size();
        int l = 0, r = len;
        
        while(l < r) {
        	int mid = (l + r) / 2;
        	if(len - mid == citations[mid]) return len - mid;
        	if(len - mid > citations[mid]) l = mid + 1;
        	else r = mid;
		}
        
        return len - l;
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
