#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()<b.length()) return addBinary(b, a);
        int i=a.length()-1, j=b.length()-1;
        int carry=0;
        while(i>=0){
            //int num;
            if(j>=0){
                //num=a[i]-'0'+b[j]-'0'+carry;
                carry+=a[i]-'0'+b[j]-'0';
            }else{
                //num=a[i]-'0'+carry;
                carry+=a[i]-'0';
            }
            
            //a[i]=num%2+'0';
            //carry=num/2;
            a[i]=carry%2+'0';
            carry/=2;
            i--;
            j--;
        }
        if(carry){
            //a.insert(0,1,'1');
            a = '1'+a;
        }
        return a;
    }
};

int main(){
    string a, b;
    cin>>a>>b;
    
    string result;
    Solution *solution=new Solution();
    result=solution->addBinary(a,b);
    
    cout<<result;
    
    return 0;
}
