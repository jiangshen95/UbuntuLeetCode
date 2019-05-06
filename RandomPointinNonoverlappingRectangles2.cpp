#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
	vector<vector<int> > rects;
public:
    Solution(vector<vector<int> >& rects) {
		this->rects = rects;
    }
    
    vector<int> pick() {
    	int sumArea = 0;
    	vector<int> selected;
    	for(auto rect : rects) {
    		int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
    		sumArea += area;
    		if(rand() % sumArea < area) selected = rect;
		}
		int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
		int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
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
