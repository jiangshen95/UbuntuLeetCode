/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        
        int num = 1;
        for(int i = 1; i < k; i++) {
//        	if(num * 10 <= n) num *= 10;
        	if(num <= n / 10) num *= 10;
        	else {
        		while(num % 10 == 9 || num == n) num /= 10;
        		num++;
			}
//			cout<<num<<"  ";
		}
		
		cout<<endl;
        
        return num;
    }
};

int main() {
	int n, k;
	cin>>n>>k;
	
	Solution *solution = new Solution();
	cout<<solution->findKthNumber(n, k);
	
	return 0;
}
