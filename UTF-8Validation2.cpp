#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int count = 0;
        for(int num : data) {
        	if(count == 0) {
        		if((num >> 5) == 0b110) count = 1;
        		else if((num >> 4) == 0b1110) count = 2;
        		else if((num >> 3) == 0b11110) count = 3;
        		else if((num >> 7) == 0) continue;
        		else return false;
			}else {
				if((num >> 6) == 0b10) count--;
				else return false;
			}
		}
		
		return count == 0;
        
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> data;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		data.push_back(num);
	}
	
	Solution *solution = new Solution();
	solution->validUtf8(data) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
