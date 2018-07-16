#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	
    	unordered_map<char, int> map1;
    	unordered_map<string, int> map2;
        
        int begin = 0, index = 0;
        string word;
        for(int i=0;i<=str.size();i++) {
        	if(str[i] == ' ' || i == str.size()) {
        		word = str.substr(begin, i - begin);
        		begin = i + 1;
        		
        		if(map1.find(pattern[index]) == map1.end()) map1[pattern[index]] = index;
				
				if(map2.find(word) == map2.end()) map2[word] = index;
				
				if(map1[pattern[index]] != map2[word]) return false;
				
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
