#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int m = nums1.size(), n = nums2.size();
        
        int i = 0;
        vector<int> nums;
        while(i <= m && i <= k) {
        	
        	if(k - i <= n) {
        		vector<int> temp = mergeArray(maxNumber(nums1, 0, m - 1, i), maxNumber(nums2, 0, n - 1, k - i));
        		
        		for(int j = 0; j < k; j++) cout<<temp[j]<<"  ";
        		cout<<endl<<endl;
        		
        		if(nums.empty() || compareArray(temp, nums)) nums = temp;
			}
        	i++;
		}
		
		return nums;
        
    }
    
    bool compareArray(vector<int> nums1, vector<int> nums2) {
    	
    	for(int i = 0; i < nums1.size(); i++) {
    		if(nums1[i] > nums2[i]) return true;
    		else if(nums1[i] < nums2[i]) return false;
		}
		return false;
    	
	}
    
    vector<int> mergeArray(vector<int> nums1, vector<int> nums2) {
    	
    	vector<int> nums;
    	int i = 0, j = 0;
    	while(i < nums1.size() && j < nums2.size()) {
    		if(nums1[i] > nums2[j]) nums.push_back(nums1[i++]);
    		else if(nums1[i] == nums2[j]) {
    			int k = 1;
    			while(i + k < nums1.size() && j + k < nums2.size() && nums1[i + k] == nums2[j + k])
    				k++;
    			if(i + k == nums1.size()) nums.push_back(nums2[j++]);
    			else if(j + k == nums2.size()) nums.push_back(nums1[i++]);
    			else if(nums1[i + k] > nums2[j + k])  nums.push_back(nums1[i++]);
    			else nums.push_back(nums2[j++]);
			}
			else nums.push_back(nums2[j++]);
		}
		while(i < nums1.size()) nums.push_back(nums1[i++]);
		while(j < nums2.size()) nums.push_back(nums2[j++]);
		
		return nums;
    	
	}
    
    vector<int> maxNumber(vector<int> nums, int begin, int end, int k) {
    	
    	vector<int> max_nums;
    	
    	if(k == 0) return max_nums;
    	if(k == end - begin + 1) return vector<int>(nums.begin() + begin, nums.begin() + end + 1);
    	
    	int max_index = begin;
    	for(int i = begin; i <= end; i++) {
    		if(nums[i] > nums[max_index]) {
    			max_index = i;
			}
		}
		
		cout<<"begin: "<<begin<<endl;
		cout<<"end: "<<end<<endl;
		cout<<"k: "<<k<<endl;
		cout<<"max_index: "<<max_index<<endl;
		system("pause");
		
		if(end - max_index + 1 > k) {
			max_nums = maxNumber(nums, max_index + 1, end, k - 1);
			max_nums.insert(max_nums.begin(), nums[max_index]);
		}else {
			max_nums = maxNumber(nums, begin, max_index - 1, k - end + max_index - 1);
			max_nums.insert(max_nums.end(), nums.begin() + max_index, nums.begin() + end + 1);
		}
		
		return max_nums;
    	
	}
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<int> nums1, nums2;
	for(int i = 0; i < m; i++) {
		int num;
		cin>>num;
		nums1.push_back(num);
	}
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums2.push_back(num);
	}
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<int> result = solution->maxNumber(nums1, nums2, k);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
}
