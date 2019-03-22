#include<iostream>
#include<sstream>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
    	stringstream ss(IP);
    	string block;
        if(IP.substr(0, 4).find('.') != string::npos) {
        	for(int i = 0; i < 4; i++) {
        		if(!getline(ss, block, '.') || !isValidIPv4Section(block)) return "Neither";
			}
			return ss.eof() ? "IPv4" : "Neither";
		}
		else if(IP.substr(0, 5).find(':') != string::npos) {
			for(int i = 0; i < 8; i++) {
				if(!getline(ss, block, ':') || !isValidIPv6Section(block)) return "Neither";
			}
			return ss.eof() ? "IPv6" : "Neither";
		}
		return "Neither";
    }
    
    bool isValidIPv4Section(string section) {
    	if(section.size() > 3 || section.size() == 0) return false;
    	if(section.size() > 1 && section[0] == '0') return false;
    	int num = 0;
    	for(char ch : section) {
    		if(ch >= '0' && ch <= '9') num = num * 10 + ch - '0';
    		else return false;
		}
		if(num <= 255) return true;
		else return false;
	}
	
	bool isValidIPv6Section(string section) {
		if(section.size() > 4 || section.size() == 0) return false;
		for(char ch : section) {
			if(!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))) return false;
		}
		return true;
	}
};

int main() {
	string ip;
	cin>>ip;
	
	Solution *solution = new Solution();
	cout<<solution->validIPAddress(ip);
	
	return 0;
}
