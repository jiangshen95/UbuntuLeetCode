#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i = 1, fizz = 0, buzz = 0; i <= n; i++) {
        	fizz++; buzz++;
        	if(fizz == 3 && buzz == 5) {
        		result.push_back("FizzBuzz");
        		fizz = 0;
        		buzz = 0;
			}
        	else if(fizz == 3) {
        		result.push_back("Fizz");
        		fizz = 0;
			}
        	else if(buzz == 5) {
        		result.push_back("Buzz");
        		buzz = 0;
			}
//        	else result.push_back(int_to_string(i));
        	else result.push_back(to_string(i));
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
