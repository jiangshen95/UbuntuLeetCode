#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	
    	int max_num = pow(10, n);
    	int used = 0;
    	int s = 1;
    	
    	for(int i = 1; i < 10; i++) {
    		used |= (1 << i);
    		s += search(i, max_num, used);
    		used = 0;
		}
    	
    	return s;
    }
    
    int search(int pre, int max_num, int used) {
    	
    	int res = 0;
    	if(pre < max_num) res++;
    	else return res;
    	
    	for(int i = 0; i < 10; i++) {
    		if(!(used & (1 << i))) {
    			used |= (1 << i);
    			int cur = pre * 10 + i;
    			res += search(cur, max_num, used);
    			used &= ~(1 << i);
			}
		}
		
		return res;
    	
	}
    
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->countNumbersWithUniqueDigits(n);
	
	return 0;
	
}
