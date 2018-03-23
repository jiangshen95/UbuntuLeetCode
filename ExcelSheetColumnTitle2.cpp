#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        
        //A B C D E F G H I J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
        //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
        
        return n == 0 ? "" : convertToTitle(n/26) + char('A' + --n%26);
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    cout<<solution->convertToTitle(n);
    
    return 0;
}
