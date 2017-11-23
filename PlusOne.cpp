#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            int num=digits[i]+carry;
            digits[i]=num%10;
            carry=num/10;
        }
        if(carry>0){
            digits.insert(digits.begin(),carry);
        }*/
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }else{
                digits[i]++;
                return digits;
            }
        }
        digits[0]=1;
        digits.push_back(0);
        
        return digits;
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<int> digits;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        digits.push_back(num);
    }
    
    vector<int> result;
    Solution *solution=new Solution();
    result=solution->plusOne(digits);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
    
    return 0;
}
