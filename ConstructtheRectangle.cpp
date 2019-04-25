#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int s = sqrt(area);
        vector<int> result;
        for(int w = s; w > 0; w--) {
        	if(area % w == 0) {
        		result.push_back(area / w);
        		result.push_back(w);
        		break;
			}
		}
		return result;
    }
};

int main() {
	
	int area;
	cin>>area;
	
	Solution *solution = new Solution();
	vector<int> result = solution->constructRectangle(area);
	for(int n : result) cout<<n<<" ";
	
	return 0;
}
