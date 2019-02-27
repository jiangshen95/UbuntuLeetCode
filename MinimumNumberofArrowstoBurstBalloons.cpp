#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int> >& points) {
        int n = points.size();
        int count = 0;
        sort(points.begin(), points.end());
        while(!points.empty()) {
        	int left = INT_MIN, right = INT_MAX;
        	vector<pair<int, int> > temp;
        	for(auto point : points) {
        		if(point.first > right || point.second < left) temp.push_back(point);
        		else {
        			cout<<point.first<<","<<point.second<<"  ";
        			left = max(point.first, left);
        			right = min(point.second, right);
				}
			}
			cout<<endl;
			points = temp;
			count++;
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
