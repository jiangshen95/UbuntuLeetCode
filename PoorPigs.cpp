#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1)); 
    }
};

int main() {
	
	int buckets, minutesToDie, minutesToTest;
	cin>>buckets>>minutesToDie>>minutesToTest;
	
	Solution *solution = new Solution();
	cout<<solution->poorPigs(buckets, minutesToDie, minutesToTest);
	
	return 0;
	
}
