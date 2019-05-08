#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    	
    	unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    	unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    	unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    	
		vector<string> result;
		for(string word : words) {
			int one = 0, two = 0, three = 0;
			for(char c : word) {
				if(c < 'a') c += 32;
				if(row1.find(c) != row1.end()) one = 1;
				if(row2.find(c) != row2.end()) two = 1;
				if(row3.find(c) != row3.end()) three = 1;
				if(one + two + three > 1) break;
			}
			if(one + two + three == 1) result.push_back(word);
		}
		
		return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<string> words;
	for(int i = 0; i < n; i++) {
		string word;
		cin>>word;
		words.push_back(word);
	}
	
	Solution *solution = new Solution();
	vector<string> result = solution->findWords(words);
	for(string word : result) cout<<word<<" ";
	
	return 0;
}
