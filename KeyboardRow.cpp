#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> m;
        for(int i = 0; i < keyboard.size(); i++) {
        	for(char c : keyboard[i]) {
        		m[c] = i;
        		m[c - 32] = i;
			}
		}
		
		vector<string> result;
		for(string word : words) {
			int i;
			for(i = 1; i < word.size(); i++) {
				if(m[word[i]] != m[word[i - 1]]) break;
			}
			if(i == word.size()) result.push_back(word);
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
