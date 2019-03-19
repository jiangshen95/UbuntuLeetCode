/*
* Time Limit Exceeded
*/
#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        
        int count = 0, len = 1;
        unordered_set<string> s;
        
        for(int i = 1; i <= p.size(); i++) {
        	if(i < p.size() && ((p[i - 1] == 'z' && p[i] == 'a') || p[i] == p[i - 1] + 1)) len++;
        	else {
        		string orderstr = p.substr(i - len, len);
        		cout<<orderstr<<endl;
        		if(s.find(orderstr) != s.end()) continue;
        		for(int j = 0; j < orderstr.size(); j++) {
        			for(int k = orderstr.size() - j; k >= 1; k--) {
        				string t = orderstr.substr(j, k);
        				if(s.find(t) == s.end()) count++;
        				else break;
        				s.insert(t);
					}
				}
				len = 1;
			}
		}
		
		return count;
    }
};

int main() {
	string p;
	cin>>p;
	
	Solution *solution = new Solution();
	cout<<solution->findSubstringInWraproundString(p);
	
	return 0;
}
