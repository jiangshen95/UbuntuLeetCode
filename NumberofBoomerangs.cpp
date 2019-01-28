#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
    	
    	int result = 0;
        for(int i = 0; i < points.size(); i++) {
//        	unordered_map<float, int> m;
			unordered_map<int, int> m;
        	for(int j = 0; j < points.size(); j++) {
        		if(i == j) continue;
        		int a = points[i].first - points[j].first;
        		int b = points[i].second - points[j].second;
        		m[a * a + b * b]++;
        		//m[distance(points[i], points[j])]++;
			}
			
			for(auto it : m) {
				if(it.second > 1) {
					result += it.second * (it.second - 1);
				}
			}
		} 
		
		return result;
    }
    
    double distance(pair<int, int> a, pair<int, int> b) {
    	return sqrt(((double)a.first - b.first) * ((double)a.first - b.first) + ((double)a.second - b.second) * ((double)a.second - b.second));
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<pair<int, int> > points;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin>>x>>y;
		points.push_back(make_pair(x, y));
	}
	
	Solution *solution = new Solution();
	cout<<solution->numberOfBoomerangs(points);
	
	return 0;
	
} 
