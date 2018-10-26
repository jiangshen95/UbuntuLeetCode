/*
** Memery Limit Exceeded 
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int> >& rectangles) {
        int lx = INT_MAX / 2, ly = INT_MAX / 2, rx = 0, ry = 0;
        for(int i = 0; i < rectangles.size(); i++) {
        	if(rectangles[i][0] + rectangles[i][1] < lx + ly) {
        		lx = rectangles[i][0];
        		ly = rectangles[i][1];
			}
			if(rectangles[i][2] + rectangles[i][3] > rx + ry) {
				rx = rectangles[i][2];
				ry = rectangles[i][3];
			}
		}
		
		vector<vector<int> > rect(rx - lx, vector<int>(ry - ly, 0));
		for(int i = 0; i < rectangles.size(); i++) {
			for(int x = rectangles[i][0]; x < rectangles[i][2]; x++) {
				for(int y = rectangles[i][1]; y < rectangles[i][3]; y++) {
					if(x >= rx || x < lx || y >= ry || y < ly) return false;
					rect[x - lx][y - ly]++;
				}
			}
		}
		
		for(int i = 0; i < rect.size(); i++) {
			for(int j = 0; j < rect[i].size(); j++)
				if(rect[i][j] != 1) return false;
		}
		
		return true;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<vector<int> > rectangles;
	for(int i = 0; i < n; i++) {
		vector<int> rect;
		for(int j = 0; j < 4; j++) {
			int coor;
			cin>>coor;
			rect.push_back(coor);
		}
		rectangles.push_back(rect);
	}
	
	Solution *solution = new Solution();
	solution->isRectangleCover(rectangles) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
