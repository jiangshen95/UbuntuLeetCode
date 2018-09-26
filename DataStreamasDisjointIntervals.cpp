#include<iostream>
#include<vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
	struct ListNode {
		Interval val;
		ListNode *next;
		ListNode(Interval val) : val(val), next(NULL) {}
	};
	ListNode *head;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        head = new ListNode(Interval(-2, -2));
    }
    
    void addNum(int val) {
        ListNode *p = head;
        ListNode *q = p->next;
        while(p != NULL) {
        	if(q == NULL) {
        		if(val == p->val.end + 1) {
        			p->val.end += 1;
        			break;
				}
        		if(val > p->val.end) {
        			p->next = new ListNode(Interval(val, val));
        			break;
				}
			}else {
				if(val == p->val.end + 1 && val == q->val.start - 1) {
					p->val.end = q->val.end;
					p->next = q->next;
					break;
				}
				if(val == p->val.end + 1) {
					p->val.end += 1;
					break;
				}
				if(val == q->val.start - 1) {
					q->val.start -= 1;
					break;
				}
				if(val > p->val.end && val < q->val.start) {
					p->next = new ListNode(Interval(val, val));
					p->next->next = q;
					break;
				}
				q = q->next;
			}
			p = p->next;
		}
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> list;
    	ListNode *p = head->next;
    	while(p) {
    		list.push_back(p->val);
    		p = p->next;
		}
		
		return list;
    }
};

int main() {
	
	SummaryRanges *obj = new SummaryRanges();
	for(int i = 0; i < 5; i++) {
		int val;
		cin>>val;
		obj->addNum(val);
		vector<Interval> params = obj->getIntervals();
		for(int j = 0; j < params.size(); j++) {
			cout<<params[j].start<<"  "<<params[j].end<<endl;
		}
	}
	
	return 0;
	
}
