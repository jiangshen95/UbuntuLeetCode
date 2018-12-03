#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	
    	int pre = 0, count = 2;
    	int result = 0;
    	for(int i = 1; i < A.size(); i++) {
    		if(A[i] - A[i - 1] != pre || i == 1) {
    			if(i != 1 && count >= 3) {
    				for(int j = 3; j <= count; j++)
    					result += count - j + 1;
				}
    			pre = A[i] - A[i - 1];
    			count = 2;
			}else {
				count++;
			}
		}
		cout<<count<<endl;
		if(count >= 3) {
			for(int j = 3; j <= count; j++) result += count - j + 1;
		}
		
		return result;
        
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> A;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		A.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->numberOfArithmeticSlices(A);
	
	return 0;
	
}
