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
		
		int result = heaters.front() - houses.front();
		int j = 0;
		for(int i = 1; i < heaters.size(); i++) {
			
			int r = 0;
			
			for(; j < houses.size(); j++) {
				if(houses[j] < heaters[i - 1]) continue;
				if(houses[j] >= heaters[i - 1] && houses[j] <= heaters[i]) {
					r = max(r, min(houses[j] - heaters[i - 1], heaters[i] - houses[j]));
				}else break;
			}
			
			result = max(result, r);
		}
		result = max(result, houses.back() - heaters.back());
		
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
