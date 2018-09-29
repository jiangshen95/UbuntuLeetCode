#include<iostream>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
    	
    	if(z == 0) return true;
    	
        if(z > x + y) return false;
        
        // m * x + n * y = z
        // z是x，y最大公约数的倍数 
        if(z % gcd(x, y) == 0) return true;
        
        return false;
        
        
    }
    
    int gcd(int a, int b) {
    	
    	while(b > 0) {
    		int c = a % b;
    		a = b;
    		b = c;
		}
		
		return a;
	}
};

int main() {
	
	int x, y, z;
	cin>>x>>y>>z;
	
	Solution *solution = new Solution();
	solution->canMeasureWater(x, y, z) ? cout<<"true" : cout<<"false";
	
	return 0;
}
