#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int> >& points) {
    	if(points.empty()) return 0;
        int count = 1;
        sort(points.begin(), points.end());
        int left = INT_MIN, right = INT_MAX;
        for(auto point : points) {
        	if(point.first > right || point.second < left) {
        		count++;
        		left = point.first;
        		right = point.second;
			}
    		else {
    			left = max(point.first, left);
    			right = min(point.second, right);
			}
		}
		return count;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<pair<int, int> > points;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin>>a>>b;
		points.push_back(make_pair(a, b));
	}
	
	Solution *solution = new Solution();
	cout<<solution->findMinArrowShots(points);
	
	return 0;
	
}
