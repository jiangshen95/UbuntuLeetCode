#include<iostream>

using namespace std;

/*
 * 排列组合 Total permutations = (m+n)! / (m! * n!) 分别有m和n个字符，有多少种排列
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if(m>n) return uniquePaths(n, m);
        
        int N=m+n-2;
        int k=m-1;
        long int res=1;
        
        for(int i=1;i<=k;i++){
            res = res*(N-i+1)/i;
            //res = res*(N-k+i)/i;
        }
        
        return int(res);
        
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    Solution *solution = new Solution();
    cout<<solution->uniquePaths(m, n);
    
    return 0;
}

