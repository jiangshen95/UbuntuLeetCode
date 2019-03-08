#include<iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
    	int n = s.size();
        for(int i = 1; i <= n / 2; i++) {
        	if(n % i == 0) {
//        		string t(s.begin(), s.begin() + i);
//        		string s2 = "";
//        		cout<<i<<" "<<t<<endl;
				string t = "";
        		for(int j = 0; j < n / i; j++) {
        			t += s.substr(0, i);
//        			s2 += t;
				}
				if(t == s) return true;
//				if(s2 == s) return true;
			}
		}
		return false;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	solution->repeatedSubstringPattern(s) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
