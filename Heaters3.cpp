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
			while(j < heaters.size() - 1 && abs(heaters[j + 1] - cur) <= abs(heaters[j] - cur)) j++;
			result = max(result, abs(heaters[j] - cur));
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
