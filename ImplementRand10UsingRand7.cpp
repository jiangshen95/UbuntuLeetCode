#include<iostream>

using namespace std;

class Solution {
public:
    int rand10() {
    	while(true) {
    		int a = rand7(), b = rand7();
        	int num = (a - 1) * 7 + b;
        	if(num <= 40) return num % 10 + 1;
		}
        
    }
};

int main() {
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++) cout<<rand10()<<" ";
	
	return 0;
}
