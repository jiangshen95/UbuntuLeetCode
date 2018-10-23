#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
    	
    	for(int i = 1; i < 10; i++) {
    		dfs(result, i, n);
		}
    	
    	return result;
    }
    
    void dfs(vector<int>& result, int v, int n) {
    	if(v <= n) result.push_back(v);
    	else return;
    	
    	for(int i = 0; i < 10; i++) dfs(result, v * 10 + i, n);
    	
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
