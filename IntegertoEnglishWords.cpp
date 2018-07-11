#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
    	
    	if(num == 0) return "Zero";
        
        vector<string> less_twenty{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
									"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		vector<string> tens{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
		
		vector<string> units{"Thousand", "Million", "Billion"};
		
		string words = "";
		int i = 0;
		
		while(num > 0) {
			string cur = "";
			if(num % 100 < 20 && num % 100 > 0) cur = less_twenty[num % 100];
			else if(num % 100 >= 20) {
				cout<<"cur: "<<cur<<endl;
				cur = tens[num % 100 / 10 - 2]  + (num % 10 == 0 ? "" : " " + less_twenty[num % 10]);
			}
			if(num / 100 > 0) {
				if(num / 100 % 10 > 0) cur = less_twenty[num / 100 % 10] + " Hundred" + (num % 100 > 0 ? " " + cur : "");
			}
			
			cout<<"cur: "<<cur<<endl;
			
			if(i == 0) words = cur;
			else {
				if(cur.size() > 0) words = cur + " " + units[i - 1] + (words.size() > 0 ? " " + words : "");
			}
			
			i ++;
			
			num /= 1000;
		}
        
        return words;
    }
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->numberToWords(num);
	
	return 0; 
	
}
