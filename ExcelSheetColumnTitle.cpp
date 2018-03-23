#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        
        //A B C D E F G H I J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
        //1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
        
        string title = "";
        
        while(n) {
            if(n%26 == 0){
                title.insert(0, 1, 'Z');
                n--;
            }
            else title.insert(0, 1, 'A' + n%26 -1);
            n = n/26;
        }
        
        return title;
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    cout<<solution->convertToTitle(n);
    
    return 0;
}
