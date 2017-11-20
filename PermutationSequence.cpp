#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string result="";
        
        bool has_append[n];
        for(int i=0;i<n;i++) has_append[i]=false;
        
        int non=1;
        for(int i=1;i<n;i++) non*=i;
        
        int m=n-1;
        
        while(m>0){
            int i=(k-1)/non;
            k-=i*non;
            //i+=n-1-m;
            for(int j=0;j<=i;j++){
                if(has_append[j]) i++;
            }
            //while(i<n&&has_append[i]) i++;
            
            
            result+=i+'1';
            has_append[i]=true;
            cout<<"i: "<<i<<endl;
            cout<<"k: "<<k<<endl;
            cout<<"str: "<<result<<endl;
            
            //if(k>=non) k-=non;
            non/=m;
            m--;
        }
        
        for(int i=0;i<n;i++){
            if(!has_append[i]){
                result+=i+'1';
                break;
            }
        }
        
        return result;
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
