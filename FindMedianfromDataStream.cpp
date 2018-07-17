/*
* Time Limit Exceeded
*/
#include<iostream>
#include<algorithm>

using namespace std;

class MedianFinder {
public:
	
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
    
    MedianFinder() {
        head = new ListNode(INT_MIN);
        count = 0;
    }
    
    void addNum(int num) {
        ListNode *cur = head;
        while(cur && cur->next) {
        	if(num >= cur->val && num <= cur->next->val) {
        		break;
			}
			cur = cur->next;
		}
		
		ListNode *add = new ListNode(num);
		add->next = cur->next;
		cur->next = add;
		
		count ++;
		 
    }
    
    double findMedian() {
        ListNode *cur = head;
        for(int i=0;i<count/2;i++) cur = cur->next;
        if(count % 2 == 0) return (double(cur->val) + cur->next->val) / 2;
        else return cur->next->val;
    }
    
private:
	ListNode *head;
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
