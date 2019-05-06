#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
	vector<vector<int> > rects;
	vector<int> areas;
	int all = 0;
public:
    Solution(vector<vector<int> >& rects) {
    	for(auto rect : rects) {
    		int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
    		areas.push_back(area);
    		all += area;
    		
		}
		this->rects = rects;
    }
    
    vector<int> pick() {
    	int area = rand() % all;
    	int index = 0;
    	while(area >= areas[index]) {
    		area -= areas[index];
    		index++;
		}
    	
    	int x1 = rects[index][0], y1 = rects[index][1], x2 = rects[index][2], y2 = rects[index][3];
    	int x = rand() % (x2 - x1 + 1) + x1, y = rand() % (y2 - y1 + 1) + y1;
    	return {x, y};
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<vector<int> > rects;
	for(int i = 0; i < n; i++) {
		vector<int> rect;
		for(int j = 0; j < 4; j++) {
			int num;
			cin>>num;
			rect.push_back(num);
		}
		rects.push_back(rect);
	}
	
	Solution *solution = new Solution(rects);
	
	vector<int> res = solution->pick();
	for(int n : res) cout<<n<<" ";
	cout<<endl;
	
	return 0;
}
