#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class MedianFinder {
private:
	multiset<int> data;
	multiset<int>::iterator median; 
public:
    MedianFinder() : median(data.end()) {
        
    }
    
    void addNum(int num) {
        
        const size_t n = data.size();
        
        data.insert(num);
        
        if(!n) {
        	median = data.begin();
		}else if(num < *median) {
			median = (n & 1 ? median : prev(median));
		}else {
			median = (n & 1 ? next(median) : median);
		}
        
    }
    
    double findMedian() {
        int n = data.size();
        if(n % 2 == 0) return (*median + *prev(median)) * 0.5;
        else return *median;
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
