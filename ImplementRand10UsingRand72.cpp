#include<iostream>

using namespace std;

class Solution {
public:
    int rand10() {
    	int num = (rand7() - 1) * 7 + rand7();
    	return (num <= 40) ? (num % 10 + 1) : rand10();
    }
};

int main() {
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++) cout<<rand10()<<" ";
	
	return 0;
}
