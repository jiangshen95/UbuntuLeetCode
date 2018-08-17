#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	
    	int n = nums.size();
    	vector<int> indexes(n);
    	for(int i = 0; i < n; i++) indexes[i] = i;
    	vector<int> counts(n);
    	
    	mergesort(nums, indexes, counts, 0, n - 1);
    	
    	return counts;
    }
    
    void mergesort(vector<int>& nums, vector<int>& indexes, vector<int>& counts, int begin, int end) {
    	
    	if(begin >= end) return;
    	
    	int mid = begin + (end - begin) / 2;
    	mergesort(nums, indexes, counts, begin, mid);
    	mergesort(nums, indexes, counts, mid + 1, end);
    	
    	merge(nums, indexes, counts, begin, end);
    	
	}
	
	void merge(vector<int>& nums, vector<int>& indexes, vector<int>& counts, int begin, int end) {
		int mid = begin + (end - begin) / 2;
		int left_index = begin, right_index = mid + 1;
		int right_count = 0;
		vector<int> new_indexes(end - begin + 1);
		
		int sort_index = 0;
		while(left_index <= mid && right_index <= end) {
			
			if(nums[indexes[right_index]] < nums[indexes[left_index]]) {
				new_indexes[sort_index] = indexes[right_index];
				right_index++;
				right_count++;
			}else {
				new_indexes[sort_index] = indexes[left_index];
				counts[indexes[left_index]] += right_count;
				left_index++;
			}
			sort_index++;
			
		}
		
		while(left_index <= mid) {
			new_indexes[sort_index++] = indexes[left_index];
			counts[indexes[left_index]] += right_count;
			left_index++;;
		}
		
		while(right_index <= end) {
			new_indexes[sort_index++] = indexes[right_index++];
		}
		
		for(int i = begin; i <= end; i++) indexes[i] = new_indexes[i - begin];
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
	
	Solution *solution = new Solution();
	vector<int> counts = solution->countSmaller(nums);
	
	for(int i = 0; i < counts.size(); i++) cout<<counts[i]<<"  ";
	
	return 0;
	
}
