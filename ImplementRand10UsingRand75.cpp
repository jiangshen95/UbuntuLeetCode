#include<iostream>

using namespace std;

class Solution {
public:
    int rand10() {
    	int i, j;
    	while((i = rand7()) > 6);
    	while((j = rand7()) > 5);
    	return (i & 1) ? j : j + 5;
    }
};

int main() {
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++) cout<<rand10()<<" ";
	
	return 0;
}
