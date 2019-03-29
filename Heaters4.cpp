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
		for(int house : houses) {
			auto pos = lower_bound(heaters.begin(), heaters.end(), house);
			int dist1 = pos == heaters.end() ? INT_MAX : *pos - house;
			int dist2 = pos == heaters.begin() ? INT_MAX : house - *(--pos);
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
