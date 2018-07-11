#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	vector<string> less_twenty{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
									"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	vector<string> tens{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
		
	vector<string> units{"Thousand", "Million", "Billion"};
public:
    string numberToWords(int num) {
    	
    	if(num == 0) return "Zero";
		
		string words = "";
		int i = 0;
		
		while(num > 0) {
			
			if(num % 1000 > 0) words = getEng(num % 1000) + (i > 0 ? " " + units[i - 1] + " " : "") + words;
			
			i ++;
			
			num /= 1000;
		}
        
        
        while(words.back() == ' ') {
        	words.erase(words.end() - 1);
		}
        
        return words;
    }
    
    string getEng(int num) {
    	
    	if(num == 0) return "";
    	else if(num < 20) return less_twenty[num];
    	else if(num < 100) return tens[num / 10 - 2] + " " + getEng(num % 10);
    	else return less_twenty[num / 100] + " Hundred " + getEng(num % 100);
    	
	}
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	cout<<solution->numberToWords(num);
	
	return 0; 
	
}
