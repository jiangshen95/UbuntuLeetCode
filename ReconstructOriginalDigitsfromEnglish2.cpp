#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        //zero one two three four five six seven eight nine
//        vector<string> words{"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> m(26, 0), nums(10, 0);
//        vector<char> chars{'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'};
        for(char c : s) m[c - 'a']++;
        
        nums[0] = m['z' - 'a'];
        nums[2] = m['w' - 'a'];
        nums[4] = m['u' - 'a'];
        nums[6] = m['x' - 'a'];
        nums[8] = m['g' - 'a'];
        nums[1] = m['o' - 'a'] - nums[0] - nums[2] - nums[4];
        nums[3] = m['h' - 'a'] - nums[8];
        nums[5] = m['f' - 'a'] - nums[4];
        nums[7] = m['s' - 'a'] - nums[6];
        nums[9] = m['i' - 'a'] - nums[6] - nums[5] - nums[8];
        
        string result = "";
        for(int i = 0; i < 10; i++) {
        	for(int j = 0; j < nums[i]; j++) result.push_back(i + '0');
		}
		
		return result;
    }
};

int main() {
	
	string s;
	cin>>s;
	
	Solution *solution = new Solution();
	cout<<solution->originalDigits(s)<<endl;
	
	return 0;
	
}
