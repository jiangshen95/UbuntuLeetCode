#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	
    	unordered_map<char, string> map1;
    	unordered_map<string, char> map2;
        
        int begin = 0, index = 0;
        string word;
        for(int i=0;i<=str.size();i++) {
        	if(str[i] == ' ' || i == str.size()) {
        		word = str.substr(begin, i - begin);
        		begin = i + 1;
        		
        		if(map1.find(pattern[index]) == map1.end()) map1[pattern[index]] = word;
        		else {
        			if(map1[pattern[index]] != word) return false;
				} 
				
				if(map2.find(word) == map2.end()) map2[word] = pattern[index];
				else {
					if(map2[word] != pattern[index]) return false;
				}
				
				index ++;
			}
		}
		
		return index == pattern.size();
    }
};

int main() {
	string pattern, str;
	getline(cin, pattern);
	getline(cin, str);
	
	Solution *solution = new Solution();
	solution->wordPattern(pattern, str) ? cout<<"True" : cout<<"False";
	
	return 0;
}
