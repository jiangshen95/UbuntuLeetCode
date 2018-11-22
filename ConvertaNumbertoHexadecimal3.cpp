#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
		vector<char> hex_num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
		string hex = "";
		unsigned n = num;
		while(n != 0) {
			hex = hex_num[n & 15] + hex;
			n >>= 4;
		}
		
		return hex;
        
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->toHex(num);
	
	return 0;
	
}
