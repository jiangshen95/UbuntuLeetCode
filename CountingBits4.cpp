#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> bits(num + 1, 0);
        
        int offset = 1;
        for(int i = 1; i <= num; i++) {
        	if(offset * 2 == i) {
        		offset *= 2;
			}
			bits[i] = bits[i - offset] + 1;
		}
		
		return bits;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	vector<int> result = solution->countBits(num);
	
	for(int i = 0; i < result.size(); i++) {
		cout<<result[i]<<"  ";
	}
	
	return 0;
	
}
