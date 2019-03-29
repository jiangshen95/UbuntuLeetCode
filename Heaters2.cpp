#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
    	
    	sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		
		int result = 0;
		int j = 0;
		for(int i = 0; i < houses.size(); i++) {
			int cur = houses[i];
			
			int left = j, right = heaters.size() - 1;
			while(left <= right) {
				int mid = (right + left) / 2;
				if(heaters[mid] < cur) left = mid + 1;
				else right = mid - 1;			
			}
			j = left;
			
			int dist1 = (left == heaters.size()) ? INT_MAX : heaters[left] - cur;
			int dist2 = (left == 0) ? INT_MAX : cur - heaters[left - 1];
			
			result = max(result, min(dist1, dist2));
		}
		
		return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> houses;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		houses.push_back(num);
	}
	
	cin>>n;
	vector<int> heaters;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		heaters.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->findRadius(houses, heaters);
	
	return 0;
	
}
