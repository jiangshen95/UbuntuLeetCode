#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        if(n == 0) return 0;
        
        vector<int> temp(n + 1, 0);
        for(int i=0;i<n;i++) {
        	if(citations[i] >= n) temp[n] ++;
        	else temp[citations[i]] ++;
		}
		
		int t = 0, result = 0;
		for(int i=n;i>=0;i--) {
			t += temp[i];
			if(t >= i) {
				result = i;
				break;
			}
		}
		
		return result;
        
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
