#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        
        int transitionTable[9][6] = {
            {-1, 0, 3, 1, 2, -1},
            {-1, 8, -1, 1, 4, 5},
            {-1, -1, -1, 4, -1, -1},
            {-1, -1, -1, 1, 2, -1},
            {-1, 8, -1, 4, -1, 5},
            {-1, -1, 6, 7, -1, -1},
            {-1, -1, -1, 7, -1, -1},
            {-1, 8, -1, 7, -1, -1},
            {-1, 8, -1, -1, -1, -1},
        };
        
        //INVALID=0, SPACE=1, SIGN=2, DIGIT=3, DOT=4, EXPONENT=5;
        int statu=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                statu=transitionTable[statu][1];
            }else if (s[i]=='+'||s[i]=='-'){
                statu=transitionTable[statu][2];
            }else if(s[i]>='0'&&s[i]<='9'){
                statu=transitionTable[statu][3];
            }else if(s[i]=='.'){
                statu=transitionTable[statu][4];
            }else if(s[i]=='e'||s[i]=='E'){
                statu=transitionTable[statu][5];
            }else{
                statu=transitionTable[statu][0];
            }
            if(statu==-1){
                return false;
            }
        }
        
        return statu==1 || statu==4 || statu==7 ||statu==8;
    }
};

int main(){
    string s;
    getline(cin, s);
    
    Solution *solution=new Solution();
    if(solution->isNumber(s)) cout<<"True";
    else cout<<"False";
    
    return 0;
}
