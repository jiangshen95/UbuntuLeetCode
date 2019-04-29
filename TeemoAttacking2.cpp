#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    	if(timeSeries.empty()) return 0;
        int begin = timeSeries[0], end = timeSeries[0] + duration, result = 0;
        for(int i = 1; i < timeSeries.size(); i++) {
        	if(timeSeries[i] > end) {
        		result += end - begin;
        		begin = timeSeries[i];
			}
			end = timeSeries[i] + duration;
		}
		result += end - begin;
		return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> timeSeries;
	for(int i = 0; i < n; i++) {
		int time;
		cin>>time;
		timeSeries.push_back(time);
	}
	
	int duration;
	cin>>duration;
	
	Solution *solution = new Solution();
	cout<<solution->findPoisonedDuration(timeSeries, duration);
	
	return 0;
}
