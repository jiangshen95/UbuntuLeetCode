#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class MedianFinder {
private:
	priority_queue<int> small;
	priority_queue<int> large; 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        small.push(num);
        large.push(-small.top());
        small.pop();
        
        if(small.size() < large.size()) {
        	small.push(-large.top());
        	large.pop();
		}
        
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() - large.top()) * 0.5;
    }
};

int main() {
	
	MedianFinder *data = new MedianFinder();
	data->addNum(1);
	data->addNum(2);
	cout<<data->findMedian()<<endl;
	
	data->addNum(3);
	cout<<data->findMedian()<<endl;
	
	return 0; 
	
}
