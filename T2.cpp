#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* tmp = result;
        ListNode* tmp2;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            if(l1 == NULL) {tmp->val = (l2->val + carry) % 10; carry = (l2->val + carry) / 10; l2 = l2->next; tmp->next = new ListNode(0); tmp2 = tmp; tmp = tmp->next; continue;}
            if(l2 == NULL) {tmp->val = (l1->val + carry) % 10; carry = (l1->val + carry) / 10; l1 = l1->next; tmp->next = new ListNode(0); tmp2 = tmp; tmp = tmp->next; continue;}
            tmp->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            tmp->next = new ListNode(0);
            tmp2 = tmp;
            tmp = tmp->next;
        }
        if(carry == 1){tmp->val = 1; tmp->next = NULL;}
        else{tmp2->next = NULL;}
        return result;
    }
};
