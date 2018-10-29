#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

class Solution {
private:
	struct Element {
		int x;
		vector<int> rect;
		Element(int x, vector<int> rect) : x(x), rect(rect) {}
//		bool operator < (const Element *c) const {
//			return x < c->x; 
//		}
	};
	
public:
	
    bool isRectangleCover(vector<vector<int> >& rectangles) {
    	auto cmp = [](Element *a, Element *b) {
    		if(a->x != b->x) return a->x > b->x;
    		else {
    			if(a->x == a->rect[0]) return true;
    			else return false;
			}
		};
    	priority_queue<Element*, vector<Element*>, decltype(cmp)> q(cmp);
    	int min_y = INT_MAX, max_y = 0;
    	for(auto rect : rectangles) {
    		q.push(new Element(rect[0], rect));
    		q.push(new Element(rect[2], rect));
    		min_y = min(min_y, rect[1]);
    		max_y = max(max_y, rect[3]);
		}
		
		struct cmp2 {
			bool operator()(vector<int> a, vector<int> b) {
				if(!(a[3] <= b[1] || b[3] <= a[1])) return false;
				else return a[3] <= b[1];
			}
		};
		
		set<vector<int>, cmp2> s;
		int y_range = 0;
		while(!q.empty()) {
			int x = q.top()->x;
			//cout<<"x: "<<x<<endl;
			while(!q.empty() && x == q.top()->x) {
				Element *e = q.top();
				q.pop();
				cout<<"x: "<<e->x<<endl;
				if(x == e->rect[0]) {
					if(!s.insert(e->rect).second) return false;
					y_range += e->rect[3] - e->rect[1];
				}else {
					s.erase(e->rect);
					y_range -= e->rect[3] - e->rect[1];
				}
			}
			
			cout<<"y_range: "<<y_range<<endl;
			
			if(!q.empty() && y_range != max_y - min_y) return false;
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
