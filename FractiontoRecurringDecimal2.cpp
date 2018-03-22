#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator == 0) return "0";
        
        string number = "";
        string decimal = "";
        
        string symbol = "";
        
        long numerator1;
        long denominator1;
        
        if(numerator<0 && denominator<0){
            numerator1 = -(long)numerator;
            denominator1 = -(long)denominator;
        }else if(numerator<0){
            numerator1 = -(long)numerator;
            denominator1 = (long)denominator;
            symbol = "-";
        }else if(denominator<0){
            numerator1 = (long)numerator;
            denominator1 = -(long)denominator;
            symbol = "-";
        }else{
            numerator1 = (long)numerator;
            denominator1 = (long)denominator;
        }
        
        if(numerator1>denominator1){
            long num = numerator1/denominator1;
            while(num){
                //number = ('0' + num%10) + number;
                number.insert(0, 1, '0' + num%10);
                num /= 10;
            }
        }
        
        if(number == "") number += '0';
        
        numerator1 = numerator1%denominator1;
        
        unordered_map<long, int> map;
        map[numerator1] = 0;
        
        while(numerator1){
            
            cout<<"numerator: "<<numerator1<<endl;
            
            long next_numerator = numerator1 * 10;
            
            cout<<"next_numerator: "<<next_numerator<<endl;
            
            decimal += next_numerator/denominator1 + '0';
            numerator1 = next_numerator%denominator1;
            
            if(map.find(numerator1) != map.end()){
                decimal.insert(map[numerator1], 1, '(');
                decimal += ')';
                break;
            }
            
            map[numerator1] = decimal.length();
            
            cin.get();
        }
        
        if(decimal == "") return symbol + number;
        
        return symbol + number + '.' + decimal;
    }
};

int main(){
    
    int numerator, denominator;
    cin>>numerator>>denominator;
    
    Solution *solution = new Solution();
    cout<<solution->fractionToDecimal(numerator, denominator);
    
    return 0;
    
}
