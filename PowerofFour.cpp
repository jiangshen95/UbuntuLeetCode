#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
    	if(num <= 0) return false;
    	float s = sqrt(num);
    	cout<<s<<endl;
    	if(s != (int)s) return false;
    	return (int)pow(2, 30) % (int)s == 0;
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	solution->isPowerOfFour(num) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
