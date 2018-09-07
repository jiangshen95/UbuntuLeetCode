#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
    	
    	int diff = 1;
    	
    	for(int i = 0; i < preorder.size(); i++) {
    		
    		if(preorder[i] == ',' || i == preorder.size() - 1) {
    			if(--diff < 0) return false;
    			if((i < preorder.size() - 1 && preorder[i - 1] != '#') || (i == preorder.size() - 1 && preorder[i] != '#')) diff += 2;
			}
    		
		}
		
		return diff == 0;
        
    }
};

int main() {
	
	string preorder;
	cin>>preorder;
	
	Solution *solution = new Solution();
	solution->isValidSerialization(preorder) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
