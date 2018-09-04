#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	
    	vector<long> sums(nums.size() + 1, 0);
    	
    	for(int i = 0; i < nums.size(); i++) {
    		sums[i + 1] = nums[i] + sums[i];
		}
		
		return countAndMergeSort(sums, 0, sums.size() - 1, lower, upper);
    	
    }
    
    int countAndMergeSort(vector<long>& sums, int begin, int end, int lower, int upper) {
    	
    	if(begin >= end) return 0;
    	
    	int mid = begin + (end - begin) / 2;
    	
    	int count = countAndMergeSort(sums, begin, mid, lower, upper) + countAndMergeSort(sums, mid + 1, end, lower, upper);
    	
    	vector<long> temp(end - begin + 1);
    	int l = mid + 1, j = mid + 1, k = mid + 1;
    	for(int i = begin, r = 0; i <= mid; i++, r++) {
    		while(j <= end && sums[j] - sums[i] < lower) j++;
    		while(k <= end && sums[k] - sums[i] <= upper) k++;
    		
    		count += k - j;
    		
			while(l <= end && sums[l] < sums[i]) temp[r++] = sums[l++];
			temp[r] = sums[i]; 
		}
		
		//copy(temp.begin(), temp.begin() + l - begin, sums.begin() + begin);
		
		for(int i = begin; i < l; i++) sums[i] = temp[i - begin];

		return count;
    	
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	int lower, upper;
	cin>>lower>>upper;
	
	Solution *solution = new Solution();
	cout<<solution->countRangeSum(nums, lower, upper);
	
	return 0;
	
}
