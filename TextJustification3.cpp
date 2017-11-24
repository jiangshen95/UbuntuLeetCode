#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> result;
        
        int width=0;
        int wordsnum=0;
        string line="";
        
        for(int i=0;i<words.size();i++){
            
            if(width+words[i].length()>maxWidth){
                width--;
                if(wordsnum==1){
                    line+=words[i-1];
                    for(int j=0;j<maxWidth-width;j++) line+=' ';
                }else{
                    int space=maxWidth-width;
                    for(int j=i-1;j>i-wordsnum;j--){
                        string wordwithspace="";
                        for(int k=0;k<=space/(wordsnum-(i-j));k++){
                            wordwithspace=' '+wordwithspace;
                        }
                        wordwithspace+=words[j];
                        line=wordwithspace+line;
                        space=space-space/(wordsnum-(i-j));
                    }
                    line=words[i-wordsnum]+line;
                }
                
                result.push_back(line);
                line="";
                width=0;
                wordsnum=0;
                
            }
            wordsnum++;
            if(i==words.size()-1){
                for(int j=i+1-wordsnum;j<i;j++){
                    line+=words[j]+' ';
                }
                line+=words[i];
                for(int j=0;j<maxWidth-(width+words[i].length());j++) line+=' ';
                result.push_back(line);
            }
            
            width+=words[i].length()+1;
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
