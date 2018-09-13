#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
    	
    	unordered_map<string, int> m;
    	set<int> s;
    	
    	vector<vector<int> > result;
    	
    	for(int i = 0; i < words.size(); i++) {
    		m[words[i]] = i;
    		s.insert(words[i].size());
		}
		
		for(int i = 0; i < words.size(); i++) {
			for(set<int>::iterator it = s.begin(); it != s.end() && *it <= words[i].size(); it++) {
				string pre = words[i].substr(0, *it);
				string pos = words[i].substr(words[i].size() - *it);
				string temp = reverseStr(pre);
				if(m.find(temp) != m.end() && m[temp] != i && isPalindrome(words[i].substr(*it, words[i].size()))) {
					result.push_back(vector<int>{i, m[temp]});
				}
				temp = reverseStr(pos);
				if(m.find(temp) != m.end() && *it < words[i].size() && isPalindrome(words[i].substr(0, words[i].size() - *it))) {
					result.push_back(vector<int>{m[temp], i});
				}
			}
		}
		
		return result;
        
    }
    
    string reverseStr(string s) {
    	int l = 0, r = s.size() - 1;
    	while(l < r) {
    		char ch = s[l];
    		s[l] = s[r];
    		s[r] = ch;
    		l++;
    		r--;
		}
		return s;
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
