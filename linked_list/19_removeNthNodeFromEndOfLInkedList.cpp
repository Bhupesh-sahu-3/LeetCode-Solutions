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


 //method1: calculate size of linked list and then delete the (size-n)th node
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



 //method2: use two pointers, move the fast pointer n steps ahead 
 //and then move both slow and fast pointers together until fast reaches the end of the linked list. 
 //At that point slow pointer will be just before the nth node from the end. 
 //Just change the links to delete the nth node from the end.
 //time:o(size of linked list)
 //space:o(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* slow=head;
       ListNode* fast=head;
       ListNode* temp = head;

        if(head==NULL) return NULL;
        if(head->next==NULL && n==1)
        return NULL;

       for(int i=0; i<n; ++i)  // o(n)   n is constant
       fast=fast->next;

       if(fast==NULL)       //if n is the size of LL then the fast reaches NULL 
       {                    //so basically we delete the head node and return head->next as new head
        ListNode* delNode = head;
        head=head->next;
        delete delNode;
        return head;
       }

       while(fast->next!=NULL)   //o(size of LL)
       {
        slow=slow->next;
        fast=fast->next;
       }
       

       ListNode* delNode = slow->next;
       slow->next = slow->next->next;
       delNode->next= nullptr;
       delete delNode;
       return head;
        
    }
};