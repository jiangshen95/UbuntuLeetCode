#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
    	
    	string result = "";
    	int keep = num.size() - k;
    	for(int i = 0; i < num.size(); i++) {
    		while(result.size() > 0 && k > 0 && num[i] < result.back()) {
    			result.pop_back();
    			k--;
			}
			result.push_back(num[i]);
		}
		result.resize(keep);
		
		while(result.front() == '0') result.erase(result.begin());
    	return result.empty() > 0 ? "0" : result;
    }
};

int main() {
	
	string num;
	cin>>num;
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	cout<<solution->removeKdigits(num, k);
	
	return 0;
	
}
