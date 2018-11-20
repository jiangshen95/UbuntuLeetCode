/*
** Time Limit Exceeded 
*/ 
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        return canCross(stones, 0, 0);
    }
    
    bool canCross(vector<int>& stones, int k, int index) {
    	if(index == stones.size() - 1) return true;
    	if(k == 0) {
    		if(index == 0 && stones[index + 1] == 1) return canCross(stones, k + 1, index + 1);
    		else return false;
		}
		
		for(int i = index + 1; i < stones.size(); i++) {
			if(stones[i] == stones[index] + k - 1 && canCross(stones, k - 1, i)) return true;
			if(stones[i] == stones[index] + k && canCross(stones, k, i)) return true;
			if(stones[i] == stones[index] + k + 1 && canCross(stones, k + 1, i)) return true;
			if(stones[i] > stones[index] + k + 1) break;
		}
		
		return false;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> stones;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		stones.push_back(num);
	}
	
	Solution *solution = new Solution();
	solution->canCross(stones) ? cout<<"true" : cout<<"false";
	
	return 0;
}
