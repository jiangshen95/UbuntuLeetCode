#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int> >& rectangles) {
//        unordered_map<pair<int, int>, int> m;
        unordered_map<string, int> m;
        int lx = INT_MAX, ly = INT_MAX, hx = 0, hy = 0;
        int measure = 0;
        for(int i = 0; i < rectangles.size(); i++) {
        	lx = min(lx, rectangles[i][0]);
        	ly = min(ly, rectangles[i][1]);
        	hx = max(hx, rectangles[i][2]);
        	hy = max(hy, rectangles[i][3]);
        	measure += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
        	
        	if(m[to_string(rectangles[i][0]) + "_" + to_string(rectangles[i][1])] & 1) return false;
        	m[to_string(rectangles[i][0]) + "_" + to_string(rectangles[i][1])] |= 1;
        	if(m[to_string(rectangles[i][0]) + "_" + to_string(rectangles[i][3])] & 2) return false;
        	m[to_string(rectangles[i][0]) + "_" + to_string(rectangles[i][3])] |= 2;
        	if(m[to_string(rectangles[i][2]) + "_" + to_string(rectangles[i][3])] & 4) return false;
        	m[to_string(rectangles[i][2]) + "_" + to_string(rectangles[i][3])] |= 4;
        	if(m[to_string(rectangles[i][2]) + "_" + to_string(rectangles[i][1])] & 8) return false;
        	m[to_string(rectangles[i][2]) + "_" + to_string(rectangles[i][1])] |= 8;
        	
//        	if(m[make_pair(rectangles[i][0], rectangles[i][1])] & 1 > 0) return false;
//        	m[make_pair(rectangles[i][0], rectangles[i][1])] |= 1;
//        	if(m[make_pair(rectangles[i][0], rectangles[i][3])] & 2 > 0) return false;
//        	m[make_pair(rectangles[i][0], rectangles[i][3])] |= 2;
//        	if(m[make_pair(rectangles[i][2], rectangles[i][3])] & 4 > 0) return false;
//        	m[make_pair(rectangles[i][2], rectangles[i][3])] |= 4;
//        	if(m[make_pair(rectangles[i][2], rectangles[i][1])] & 8 > 0) return false;
//        	m[make_pair(rectangles[i][2], rectangles[i][1])] |= 8;
		}
		cout<<measure<<endl;
		cout<<lx<<"  "<<ly<<"  "<<hx<<"  "<<hy<<endl;
		int count = 0;
		for(auto it = m.begin(); it != m.end(); it++) {
			int t = it->second;
			if(t == 1 || t == 2 || t == 4 || t == 8) count++;
		}
		if(count == 4 && measure == (hx - lx) * (hy - ly)) return true;
		return false;
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
