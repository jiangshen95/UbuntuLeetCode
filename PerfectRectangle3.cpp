#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int> >& rectangles) {
    	unordered_set<string> st;
        int lx = INT_MAX, ly = INT_MAX, hx = 0, hy = 0;
        int measure = 0;
        
        for(auto rect : rectangles) {
        	lx = min(lx, rect[0]);
        	ly = min(ly, rect[1]);
        	hx = max(hx, rect[2]);
        	hy = max(hy, rect[3]);
        	measure += (rect[2] - rect[0]) * (rect[3] - rect[1]);
        	
        	string s1 = to_string(rect[0]) + "_" + to_string(rect[1]);
        	string s2 = to_string(rect[0]) + "_" + to_string(rect[3]);
        	string s3 = to_string(rect[2]) + "_" + to_string(rect[3]);
        	string s4 = to_string(rect[2]) + "_" + to_string(rect[1]);
        	
        	if(st.find(s1) != st.end()) st.erase(s1);
        	else st.insert(s1);
        	if(st.find(s2) != st.end()) st.erase(s2);
        	else st.insert(s2);
        	if(st.find(s3) != st.end()) st.erase(s3);
        	else st.insert(s3);
        	if(st.find(s4) != st.end()) st.erase(s4);
        	else st.insert(s4);
		}
		
		string s1 = to_string(lx) + "_" + to_string(ly);
		string s2 = to_string(lx) + "_" + to_string(hy);
		string s3 = to_string(hx) + "_" + to_string(ly);
		string s4 = to_string(hx) + "_" + to_string(hy);
		
		if(!st.count(s1) || !st.count(s2) || !st.count(s3) || !st.count(s4)) return false;
        
		return st.size() == 4 && measure == (hx - lx) * (hy - ly);
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
