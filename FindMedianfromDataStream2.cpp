#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        
        if(data.size() == 0) data.push_back(num);
		else if(num >= data.back()) data.push_back(num);
		else if(num <= data.front()) data.insert(data.begin(), num);
		else {
			for(int i=0;i<data.size()-1;i++) {
	        	if(num >= data[i] && num <= data[i + 1]) {
	        		data.insert(data.begin() + i + 1, num);
	        		break;
				}
			}
		}
        
        count ++;
    }
    
    double findMedian() {
        
        if(count % 2 == 0) return (double(data[count / 2 - 1]) + data[count / 2]) / 2;
        else return data[count / 2];
        
    }
private:
	vector<int> data;
	int count;
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
