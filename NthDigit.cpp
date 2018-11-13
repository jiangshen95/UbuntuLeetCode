#include<iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        
        int digits = 1, j = 1;
        long long i = 9;
        while(n - i * digits > 0) {
        	n -= i * digits;
        	digits += 1;
        	i *= 10;
        	cout<<n<<endl;
        	cout<<i<<endl;
        	j *= 10;
		}
		
		int m = (n - 1) / digits;
		int num = j + m;
		
		cout<<num<<endl;
		
		int where = (n - 1) % digits;
		where = digits - where;
		
		while(--where > 0) {
			num /= 10;
		}
		
		
		return num % 10;
        
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->findNthDigit(n);
	
	return 0;
	
}
