#include<iostream>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
//removing duplicate from exiting list.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        //checking for empty list
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode* it = head->next;  // main iterator
        ListNode* curr = head;  // current node in final list
        while(it != NULL)
        {
            //checking for duplicate values
            if(it->val != curr->val)
            {
                // update final list
                curr->next = it;
                curr = curr->next;
            }
            
            //if duplicate values appear deleting them
            it = it->next;
        }
        // end list
        curr->next = NULL;
        return head;
    }
};