#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i = 1; i <= n; i++) {
        	string s = "";
        	if(i % 3 == 0) s += "Fizz";
        	if(i % 5 == 0) s += "Buzz";
        	if(s == "") s += to_string(i);
        	result.push_back(s);
		}
		
		return result;
    }
    
    string int_to_string(int num) {
    	string result = "";
    	while(num > 0) {
    		result += (num % 10 + '0');
    		num /= 10;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	vector<string> result = solution->fizzBuzz(n);
	
	for(auto s : result) cout<<s<<"  ";
	
	return 0;
}
