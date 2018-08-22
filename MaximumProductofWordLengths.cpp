#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
    	
    	int n = words.size();
    	
        vector<vector<int> > m(n, vector<int>(26, 0));
        
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < words[i].size(); j++) {
        		m[i][words[i][j] - 'a']++;
			}
		}
		
		int maxpro = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				bool hasSame = false;
				for(int k = 0; k < words[i].size(); k++) {
					if(m[j][words[i][k] - 'a'] > 0) {
						hasSame = true;
						break;
					}
				}
				if(!hasSame) {
					if(words[i].size() * words[j].size() > maxpro)
						maxpro = words[i].size() * words[j].size();
				}
			}
		}
		
		return maxpro;
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
	cout<<solution->maxProduct(words);
	
	return 0;
	
}
