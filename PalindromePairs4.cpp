#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	struct TrieNode {
		vector<TrieNode*> next;
		int index = -1;
		vector<int> list;
		TrieNode() {
			next = vector<TrieNode*>(26, NULL);
		}
	};
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
    	
    	vector<vector<int> > result;
    	
    	TrieNode *root = new TrieNode();
    	for(int i = 0; i < words.size(); i++) addWord(root, words[i], i);
    	for(int i = 0; i < words.size(); i++) search(root, words, i, result);
    	
    	return result;
        
    }
    
    void addWord(TrieNode *root, string word, int index) {
    	
    	for(int i = word.size() - 1; i >= 0; i--) {
    		int j = word[i] - 'a';
    		if(root->next[j] == NULL) root->next[j] = new TrieNode();
    		if(isPalindrome(word.substr(0, i + 1))) root->list.push_back(index);
    		root = root->next[j];
		}
		
		root->list.push_back(index);
		root->index = index;
    	
	}
	
	void search(TrieNode *root, vector<string> words, int i, vector<vector<int> >& result) {
		for(int j = 0; j < words[i].size(); j++) {
			if(root->index >= 0 && root->index != i && isPalindrome(words[i].substr(j))) {
				result.push_back(vector<int>{i, root->index});
			}
			
			root = root->next[words[i][j] - 'a'];
			if(root == NULL) return;
		}
		
		for(int j : root->list) {
			if(i == j) continue;
			result.push_back(vector<int>{i, j});
		}
	}
    
    bool isPalindrome(string s) {
    	
    	int l = 0, r = s.length() - 1;
    	while(l < r) {
    		if(s[l] != s[r]) return false;
    		l++;
    		r--;
		}
		
		return true;
    	
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
	vector<vector<int> > result = solution->palindromePairs(words);
	
	for(int i = 0; i < result.size(); i++) {
		cout<<result[i][0]<<"  "<<result[i][1]<<endl;
	}
	
	return 0;
	
}
