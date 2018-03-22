#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = 0, l2 = 0;
        while(l1<version1.length() && l2<version2.length()){
            int level1 = 0;
            int level2 = 0;
            while(l1<version1.length() && version1[l1]!='.'){
                level1 = level1*10 + version1[l1] - '0';
                l1++;
            }
            while(l2<version2.length() && version2[l2]!='.'){
                level2 = level2*10 + version2[l2] - '0';
                l2++;
            }
            if(level1>level2) return 1;
            else if (level1<level2) return -1;
            else{
                l1++;
                l2++;
            }
        }
        
        if(l1<version1.length()){
            for(;l1<version1.length();l1++){
                if(version1[l1]!='0' && version1[l1]!='.') return 1;
            }
            return 0;
        }
        else if(l2<version2.length()){
            for(;l2<version2.length();l2++){
                if(version2[l2]!='0' && version2[l2]!='.') return -1;
            }
            return 0;
        }
        else return 0;
    }
};

int main(){
    
    string version1, version2;
    cin>>version1>>version2;
    
    Solution *solution = new Solution();
    cout<<solution->compareVersion(version1, version2);
    
    return 0;
    
}
