#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class MedianFinder {
private:
	priority_queue<int> lo;
	priority_queue<int, vector<int>, greater<int> > hi; 
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        lo.push(num);
        
        hi.push(lo.top());
        lo.pop();
        
        if(lo.size() < hi.size()) {
        	lo.push(hi.top());
			 hi.pop();
		}
        
    }
    
    double findMedian() {
        return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
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
