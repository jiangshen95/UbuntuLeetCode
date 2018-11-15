#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
    	int n = num.size();
    	if(k >= n) return "0";
    	
    	stack<char> s;
    	for(int i = 0; i < n; i++) {
    		while(!s.empty() && k > 0 && num[i] < s.top()) {
    			s.pop();
    			k--;
			}
			s.push(num[i]);
		}
		
		while(k > 0) {
			s.pop();
			k--;
		}
		
		string result = "";
		while(!s.empty()) {
			result = s.top() + result;
			s.pop();
		}
		
		while(result.front() == '0') result.erase(result.begin());
		
		return result.size() > 0 ? result : "0";
    	
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
