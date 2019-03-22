#include<iostream>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        string result;
        char sp = 0;
        int count = 0;
        for(int i = 0, j = 0; i <= IP.size(); i++) {
        	char ch = i == IP.size() ? sp : IP[i];
        	if(ch != '.' && ch != ':' && !((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) return "Neither";
        	if(ch == '.' || ch == ':') {
        		if(!sp) sp = ch;
        		else if(sp != ch) return "Neither";
        		string section = IP.substr(j, i - j);
        		if(!((sp == '.' && isValidIPv4Section(section)) || (sp == ':' && isValidIPv6Section(section)))) return "Neither";
        		count++;
        		if((sp == '.' && count > 4) || (sp == ':' && count > 8)) return "Neither";
        		j = i + 1;
			} 
		}
		
		if(sp == '.' && count == 4) return "IPv4";
		else if(sp == ':' && count == 8) return "IPv6";
		else return "Neither";
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
