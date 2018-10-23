#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
    	
    	helper(result, 1, n);
    	
    	return result;
    }
    
    void helper(vector<int>& result, int v, int n) {
    	if(v <= n) result.push_back(v);
    	else return;
    	helper(result, v * 10, n);
    	
    	if(++v % 10 != 0) helper(result, v, n);
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
