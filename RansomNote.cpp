#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letters(26, 0);
        for(int i = 0; i < magazine.size(); i++) {
        	letters[magazine[i] - 'a']++;
		}
		
		for(int i = 0; i < ransomNote.size(); i++) {
			if(letters[ransomNote[i] - 'a']-- <= 0) return false;
		}
		
		return true;
    }
};

int main() {
	string ransomNote, magazine;
	cin>>ransomNote;
	cin>>magazine;
	
	Solution *solution = new Solution();
	solution->canConstruct(ransomNote, magazine) ? cout<<"true" : cout<<"false";
	
	return 0;
}
