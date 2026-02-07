/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //method1: Reverse list and remove nth node
 //time:o(length of LL+ length of LL - n)
 //space:o(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp=head;
       ListNode* prev = NULL; 
       int size=0;
       if(head==NULL) return NULL; //no node present
       if(head->next==NULL && n==1) //only one node present and we are asked to delete that node
       return NULL;

       while(temp)  //calculate size of the linked list
       {                //o(length of linked list) time
        size++;
        temp=temp->next;
       }

       if(size==n)     //if we are asked to delete last node starting from the end then we dont have (n-1)th node
       {                    //in that case we just shift the head to the next node and return it as new head
        newHead=head->next;
        delete head;
        return newHead;
       }

       int prevNode=size-n;    // (n-1)th node, just before the nth node
       temp=head;
       int count=0;
       while(temp)              //o(length-n) time
       {
        count++;
        if(count==prevNode)           //just change the links
        {
            ListNode* front=temp->next;
            temp->next=front->next;
            front->next=nullptr;
            delete front;
            break;    
        }
        temp=temp->next;
       }

        return head;
    }
};