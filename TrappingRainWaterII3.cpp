#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int> >& heightMap) {
        if(heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        if(m < 3 || n < 3) return 0;
        
        vector<vector<int> > wetMap(m, vector<int>(n));
        int result = 0;
        for(int i = 1; i < m - 1; i++) wetMap[i] = calculate(heightMap[i]);
        
        for(int i = 1; i < n - 1; i++) {
        	vector<int> col;
        	for(int j = 0; j < m; j++) col.push_back(heightMap[j][i]);
        	
        	vector<int> colResult = calculate(col);
        	
        	for(int j = 0; j < m; j++) {
        		wetMap[j][i] = max(colResult[j], wetMap[j][i]);
        		result += wetMap[j][i];
			}
		}
		
		bool spillWater = true;
		vector<vector<int> > dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
		while(spillWater) {
			spillWater = false;
			for(int i = 1; i < m - 1; i++) {
				for(int j = 1; j < n - 1; j++) {
					if(wetMap[i][j] > 0) {
						for(int k = 0; k < 4; k++) {
							int x = i + dir[k][0], y = j + dir[k][1];
							int curHeight = wetMap[i][j] + heightMap[i][j];
							int neighborHeight = wetMap[x][y] + heightMap[x][y];
							if(curHeight > neighborHeight) {
								int spilledWater = curHeight - max(neighborHeight, heightMap[i][j]);
								wetMap[i][j] = max(0, wetMap[i][j] - spilledWater);
								result -= spilledWater;
								spillWater = true;
							}
						}
					}
				}
			}
		}
		
		return result;
        
    }
    
    /* the same with trapping rain water 1 */
    vector<int> calculate(vector<int> height) {
    	int n = height.size();
    	vector<int> result(n, 0);
    	stack<int> s;
    	for(int i = 0; i < n; i++) {
    		if(s.empty() || height[i] <= height[s.top()]) s.push(i);
    		else {
    			int bottom = s.top();
    			s.pop();
    			if(!s.empty()) {
    				for(int j = s.top() + 1; j < i; j++)
						result[j] += min(height[s.top()], height[i]) - height[bottom];
				}
				i--;
			}
		}
		
		return result;
	}
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<vector<int> > heightMap;
	for(int i = 0; i < m; i++) {
		vector<int> row;
		for(int j = 0; j < n; j++) {
			int h;
			cin>>h;
			row.push_back(h);
		}
		heightMap.push_back(row);
	}
	
	Solution *solution = new Solution();
	cout<<solution->trapRainWater(heightMap);
	
	return 0;
	
}
