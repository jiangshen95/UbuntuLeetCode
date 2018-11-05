#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        
        int i = 0;
        return decodeString(s, i);
        
    }
    
    string decodeString(string& s, int& i) {
    	
    	string result = "";
    	
    	while(i < s.size() && s[i] != ']') {
    		if(!isdigit(s[i])) {
    			result += s[i++];
			}else {
				int n = 0;
				while(i < s.size() && isdigit(s[i])) n = n * 10 + s[i++] - '0';
				i++;
				string t = decodeString(s, i);
				i++;
				
				for(int j = 0; j < n; j++) result += t;
			}
		}
		
		return result;
    	
	}
};

int main() {
	string s;
	cin>>s;
	Solution *solution = new Solution();
	cout<<solution->decodeString(s)<<endl;
	return 0;
}
