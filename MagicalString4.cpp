#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	class Kolakoski {
	private:
		vector<int> queue{1, 2, 2};
		int first = 0, last = 2;
		Kolakoski *source = NULL;
	public:
		int next() {
			if(first > last) {
				if(source == NULL) {
					source = new Kolakoski();
					source->next();
					source->next();
				}
				int output = queue[last % 3] ^ 3;
				for(int i = source->next(); i > 0; i--) {
					queue[++last % 3] = output;
				}
			}
			return queue[first++ % 3];
		}
	};
public:
    int magicalString(int n) {
        Kolakoski *kolakoski = new Kolakoski();
        int count = 0;
        for(int i = 0; i < n; i++) {
        	if(kolakoski->next() == 1) count++;
		}
		return count;
    }
};

int main() {
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->magicalString(n);
	
	return 0;
}
