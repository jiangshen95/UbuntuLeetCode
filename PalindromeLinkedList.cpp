#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return isPalindrome(head, NULL);
    }
    
    bool isPalindrome(ListNode *begin, ListNode *end){
        if(begin == end || begin->next == end) return true;
        ListNode *p = begin;
        while(p->next != end) p = p->next;
        if(begin->val == p->val) return isPalindrome(begin->next, p);
        else return false;
    }
};

int main(){
    
    int n;
    cin>>n;
    
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        p->next = new ListNode(num);
        p = p->next;
    }
    head = head->next;
    
    Solution *solution = new Solution();
    solution->isPalindrome(head) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
