#include<iostream>

using namespace std;

bool isBadVersion(int version);

bool isBadVersion(int version) {
	return version >= 4 ? true : false;
}
/*
*  Time Limit Exceed
*/
class Solution {
public:
    int firstBadVersion(int n) {
        
        int i = 1, j = n;
        
//        while(i < j) {
//        	
//        	int mid = (i + j) / 2;
//        	if(isBadVersion(mid)) j = mid;
//        	else i = mid + 1;
//        	
//		}

		while(i <= j) {
        	
        	//int mid = (i + j) / 2;  i + j 可能会溢出 
        	int mid = i + (j - i) / 2;
        	if(isBadVersion(mid)) j = mid - 1;
        	else i = mid + 1;
        	
		}
        
        return i;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->firstBadVersion(n);
	
	return 0;
}
