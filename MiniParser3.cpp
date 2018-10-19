#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    NestedInteger deserialize(string s) {
        vector<NestedInteger> stack;
        stack.emplace_back(NestedInteger());
        
        for(int i = 0; i < s.size(); i++) {
        	if(s[i] == '[') {
        		stack.push_back(NestedInteger());
        		
			}else if(s[i] == ']') {
				NestedInteger ni = stack.back();
				stack.pop_back();
				stack.back().add(ni);
			}else if(s[i] == ',') {
				continue;
			}else {
				int num = 0;
				int sign = 1;
				if(s[i] == '-') {
					sign = -1;
					i++;
				}
				while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 + s[i] - '0';
					i++;
				}
				num *= sign;
				i--;

				stack.back().add(NestedInteger(num));
			}
		}
        
        return stack.back().getList().back();
    }
};

int main() {
	
//	string s;
//	cin>>s;
//	
//	Solution *solution = new Solution();
//	solution->deserialize(s);
	
//	vector<int> test{1, 2, 3};
//	test.back() = 4;
//	cout<<test[2]<<endl;

	vector<int> test;
	int a = 3;
	test.emplace_back(a);
	a = 4;
	cout<<test.back()<<endl;
		
	return 0;
	
}
