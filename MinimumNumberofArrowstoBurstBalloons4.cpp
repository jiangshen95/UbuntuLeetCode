#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int> >& points) {
        int count = 0;
        int end = INT_MIN;
        sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) {
        	if(a.second == b.second) return a.first < b.first;
        	else return a.second < b.second;
		});
        for(auto point : points) {
        	if(point.first > end || end == INT_MIN) {
        		count++;
        		end = point.second;
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
