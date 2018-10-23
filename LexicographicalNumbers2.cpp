#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
    	vector<int> s;
    	
    	s.push_back(1);
    	result.push_back(1);
    	
    	while(!s.empty()) {
    		int v = result.back();
    		while(v * 10 <= n) {
    			result.push_back(v * 10);
    			s.push_back(v * 10);
    			v *= 10;
			}
			//cout<<v<<endl;
			//system("pause");
			while(!s.empty() && (v % 10 == 9 || v == n)) {
				s.pop_back();
				v = s.back();
			}
			
			if(!s.empty()) {
				s.pop_back();
				s.push_back(v + 1);
				result.push_back(v + 1);
			}
			
		}
		
		return result;
    	
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	Solution solution = Solution();
	vector<int> result = solution.lexicalOrder(n);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
	
}
