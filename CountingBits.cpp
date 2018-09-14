#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> bits(num + 1, 0);
        
        for(int i = 1; i <= num; i++) {
        	if(i % 2 == 1) bits[i] = bits[i - 1] + 1;
        	else {
        		bits[i] = bits[i / 2];
			}
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
