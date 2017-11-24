#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> result;
        
        for(int i=0, k, l;i<words.size();i+=k){
            for(k=l=0;i+k<words.size() and l+words[i+k].size()<=maxWidth-k;k++){
                l+=words[i+k].size();
            }
            string tmp="";
            tmp+=words[i];
            for(int j=0;j<k-1;j++){
                if(i+k>=words.size()) tmp+=' ';
                else tmp.append((maxWidth-l)/(k-1)+(j<(maxWidth-l)%(k-1)),' ');
                tmp+=words[i+j+1];
            }
            tmp.append(maxWidth-tmp.length(), ' ');
            result.push_back(tmp);
        }
        
        return result;
    }
};

int main(){
    int n;
    cin>>n;
    int maxWidth;
    cin>>maxWidth;
    
    vector<string> words;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        words.push_back(s);
    }
    
    vector<string> result;
    Solution *solution=new Solution();
    result=solution->fullJustify(words, maxWidth);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    
    return 0;
}

