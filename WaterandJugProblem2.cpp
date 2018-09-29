#include<iostream>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
    	
    	if(z == 0) return true;
    	if(z == x + y) return true;
    	
        if(z > x + y) return false;
        
        if(x > y)  swap(x, y);
        int v = 0;
        
        do {
        	if(v < x) v += y;
        	else v -= x;
        	if(v == z) return true;
		} while(v != 0);
		
		return false;
        
        
    }
    
};

int main() {
	
	int x, y, z;
	cin>>x>>y>>z;
	
	Solution *solution = new Solution();
	solution->canMeasureWater(x, y, z) ? cout<<"true" : cout<<"false";
	
	return 0;
} 
