#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int bytes = 0;
        for(int i = 0; i < data.size(); i++) {
        	
        	int num = data[i];
        	num &= 0xFF;
        	int mask = 0x80;
        	if(num & mask == 0) {
        		if(bytes != 0) return false;
        		else continue;
			}
			
        	int count = 0;
        	while(num & mask) {
        		mask >>= 1;
        		count++;
			}
			if(count > 4) return false;
			if(count == 1) {
				if(bytes == 0) return false;
				else bytes--;
			}else if(count > 1) {
				if(bytes != 0) return false;
				bytes = count - 1;
			}
		}
		
		return bytes == 0;
        
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
