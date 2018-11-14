#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    	
    	vector<string> result;
    	
    	for(int h = 0; h < 12; h++) {
    		for(int m = 0; m < 60; m++) {
    			//if(bitCount(h) + bitCount(m) == num) {
    			if(bitCount((h << 6) + m) == num) {
    				result.push_back(to_string(h) + (m >= 10 ? ":" : ":0") + to_string(m));
				}
			}
		}
		
		return result;
    }
    
    int bitCount(int num) {
    	int count = 0;
    	while(num) {
    		num &= num - 1;
    		count++;
		}
		
		return count;
	}
    
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	vector<string> result = solution->readBinaryWatch(num);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	cout<<endl;
	
	return 0;
	
}
