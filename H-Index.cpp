#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        //qsort(citations, 0, citations.size() - 1);
        sort(citations.begin(), citations.end(), greater<int>());
        
        int i = 0;
        for(i=0;i<citations.size();i++) {
        	if(i + 1 > citations[i]) break;
		}
		
		return i;
        
    }
    
    void qsort(vector<int>& nums, int l, int r) {
    	if(l >= r) return;
    	int i = l, j = r;
    	int v = nums[l];
    	
    	while(i < j) {
    		while(i < j && nums[j] <= v) j --;
    		nums[i] = nums[j];
    		while(i < j && nums[i] >= v) i ++;
    		nums[j] = nums[i];
		}
		nums[i] = v;
		
		qsort(nums, l, i);
		qsort(nums, i + 1, r);
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
