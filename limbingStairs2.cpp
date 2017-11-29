#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int q[2][2]={{1,1},{1,0}};
        int res[2][2]={{1,1},{1,0}};
        
        //for(int i=0;i<n;i++){
         //   multiMatrix(res, q);
        //}
        n--;
        while(n>0){
            if(n%2){
                multiMatrix(res,q);
            }
            n/=2;
            multiMatrix(q,q);
        }
        
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return res[0][0];
        
    }
    void multiMatrix(int a[][2], int b[][2]){
        int c[2][2];
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                int sum=0;
                for(int k=0;k<2;k++){
                    sum+=a[i][k]*b[k][j];
                }
                c[i][j]=sum;
            }
        }
        
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                a[i][j]=c[i][j];
            }
        }
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution *solution=new Solution();
    cout<<solution->climbStairs(n);
    
    return 0;
}
