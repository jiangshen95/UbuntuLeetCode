#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    	
    	vector<string> result;
    	
    	getTimes(num, 0, 0, 0, result);
		
		return result;
    }
    
    void getTimes(int num, int hour, int minute, int index, vector<string>& result) {
    	if(num == 0) {
    		result.push_back(to_string(hour) + (minute >= 10 ? ":" : ":0") + to_string(minute));
    		return;
		}
		for(int i = index; i < 10; i++) {
			if(i < 4) {
				int t = hour + (1 << i);
				if(t < 12) getTimes(num - 1, t, minute, i + 1, result);
			}else {
				int t = minute + (1 << (i - 4));
				if(t < 60) getTimes(num - 1, hour, t, i + 1, result);
			}
		}
		
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
