#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
    	
    	int cur = 1;
    	
    	for(int i = 0; i < n; i++) {
    		result.push_back(cur);
    		if(cur * 10 <= n) {
    			cur *= 10;
			}else {
				if(cur >= n) cur /= 10;
				cur += 1;
				while(cur % 10 == 0) cur /= 10;
			}
		}
		
		return result;
    	
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	Solution solution = Solution();
	vector<int> result = solution.lexicalOrder(n);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
	
}
