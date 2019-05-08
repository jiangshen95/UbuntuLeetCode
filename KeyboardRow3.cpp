#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    	vector<string> keyboard{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    	vector<int> dict(26);
    	
    	for(int i = 0; i < keyboard.size(); i++) {
    		for(char c : keyboard[i]) dict[c - 'a'] = 1 << i; 
		}
    	
		vector<string> result;
		for(string word : words) {
			int r = 7;
			for(char c : word) {
				if(c < 'a') c += 32;
				r &= dict[c - 'a'];
				if(r == 0) break;
			}
			if(r) result.push_back(word);
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
