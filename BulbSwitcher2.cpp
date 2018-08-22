#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
    	
    	if(n == 0) return 0;
    	int count = 3;
    	int border = 0;
    	int i = 0;
    	while(n > border) {
    		border += count;
    		count += 2;
    		i++;
		}
		
		return i;
    	
    }
};

int main() {
	
//	Solution *solution = new Solution();
//	
//	for(int i = 2; i <= 30; i++) {
//		cout<<i<<": "<<solution->bulbSwitch(i)<<endl;
//	}
	
	int n;
	cin>>n;
	Solution *solution = new Solution();
	cout<<solution->bulbSwitch(n);
	return 0;
}
