#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string result="";
        
        for(int i=1;i<=n;i++) result+=i+'0';
        
        for(int i=1;i<k;i++){
            
            int j;
            for(j=n-1;j>0;j--){
                if(result[j]>result[j-1]){
                    break;
                }
            }
            
            int l=j-1;
            for(j=n-1;j>l;j--){
                if(result[j]>result[l]){
                    break;
                }
            }
            
            int r=j;
            
            swap(result[l], result[r]);
            
            reverse(result, l+1, n-1);
            
        }
        
        return result;
    }
    
    void swap(char& a, char& b){
        char v=a;
        a=b;
        b=v;
    }
    
    void reverse(string& s, int l, int r){
        while(l<r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    
    string result;
    Solution *solution=new Solution();
    result=solution->getPermutation(n, k);
    cout<<result;
    
    return 0;
}

