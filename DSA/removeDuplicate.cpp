#include<iostream>
using namespace std;


struct Listnode {
      int val;
      Listnode *next;
      Listnode() : val(0), next(nullptr) {}
      Listnode(int x) : val(x), next(nullptr) {}
      Listnode(int x, Listnode *next) : val(x), next(next) {}
 };

//removing duplicate from exiting list.
class Solution {
public:
    Listnode* deleteDuplicates(Listnode* head) {

        //checking for empty list
        if(head == NULL)
        {
            return NULL;
        }

        Listnode* it = head->next;  // main iterator
        Listnode* curr = head;  // current node in final list
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
