#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    	
    	vector<string> result;
    	vector<int> bytes(10, 0);
    	
    	helper(bytes, num, 0, result);
		
		return result;
    }
    
    void helper(vector<int>& bytes, int num, int i, vector<string>& result) {
    	if(num == 0) {
    		string t = getTime(bytes);
    		if(t.size() > 0) result.push_back(t);
    		return;
		}
		
		if(i >= 10) return;
		
		bytes[i] = 0;
		helper(bytes, num, i + 1, result);
		
		bytes[i] = 1;
		helper(bytes, num - 1, i + 1, result);
		bytes[i] = 0;
	}
	
	string getTime(vector<int> bytes) {
		int hour = 0;
		for(int i = 0; i < 4; i++) {
			if(bytes[i]) hour += 1 << i;
		}
		
		int minute = 0;
		for(int i = 4; i < bytes.size(); i++)
			if(bytes[i]) minute += 1 << (i - 4);
		
		if(hour < 12 && minute < 60)
			return to_string(hour) + (minute >= 10 ? ":" : ":0") + to_string(minute);
		else return "";
	}
    
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	vector<string> result = solution->readBinaryWatch(num);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	cout<<endl;
	
	return 0;
	
}
