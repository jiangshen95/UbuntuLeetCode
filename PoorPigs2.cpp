#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int pigs = 0;
        while(pow(minutesToTest / minutesToDie + 1, pigs) < buckets) pigs++;
        return pigs;
    }
};

int main() {
	
	int buckets, minutesToDie, minutesToTest;
	cin>>buckets>>minutesToDie>>minutesToTest;
	
	Solution *solution = new Solution();
	cout<<solution->poorPigs(buckets, minutesToDie, minutesToTest);
	
	return 0;
	
}
