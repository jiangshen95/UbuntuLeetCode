/*
** Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
    	
    	vector<vector<int> > result;
        
        for(int i = 0; i < words.size(); i++) {
        	for(int j = i + 1; j < words.size(); j++) {
        		if(isPalindrome(words[i] + words[j])) {
        			result.push_back(vector<int>{i, j});
        			if(words[i].length() == words[j].length()) result.push_back(vector<int>{j, i});
				}
				if(words[i].length() != words[j].length() && isPalindrome(words[j] + words[i])) {
					result.push_back(vector<int>{j, i});
				}
			}
		}
		
		return result;
        
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
