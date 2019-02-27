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
        int end = points[0].second;
        for(int i = 1; i < points.size(); i++) {
        	if(points[i].first <= end) end = min(end, points[i].second);
        	else {
        		count++;
        		end = points[i].second;
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
