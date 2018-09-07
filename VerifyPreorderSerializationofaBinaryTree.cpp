#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
    	
    	vector<char> stack;
        
        for(int i = 0; i < preorder.size(); i++) {
        	
        	if(preorder[i] == ',') continue;
        	else if(preorder[i] == '#') {
        		if(stack.empty() && preorder.size() == 1) {
        			return true;
				}else if(stack.empty()) return false;
				
				while(stack.back() == '#') {
					stack.pop_back();
					if(stack.empty()) return false;
					stack.pop_back();
					if(stack.empty() && i == preorder.size() - 1) return true;
					else if(stack.empty()) return false;
				}
				
				stack.push_back('#');
				
			}else {
				if(i == preorder.size() - 1 || preorder[i + 1] == ',')
					stack.push_back(preorder[i]);
			}
        	
		}
		
		return false;
        
    }
};

int main() {
	
	string preorder;
	cin>>preorder;
	
	Solution *solution = new Solution();
	solution->isValidSerialization(preorder) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
