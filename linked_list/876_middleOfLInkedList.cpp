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

 //Brute Force
 //o(n + n/2) time
 //o(1) space
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0;
        int count=0;
        ListNode* temp = head;
        while(temp)                 //o(n)
        {
            n++;
            temp=temp->next;
        }
        if(n==0)
        return NULL;
        int mid =((n/2)+1);
        temp=head;
        while(temp)                 //o(n/2)
        {
            count++;
            if(count==mid)
            break;
            temp=temp->next;
        }
       return temp; 
    }
};


 //tortoise and hair algo
 //o(n/2) time and o(1) space
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while( fast!=NULL && fast->next != NULL )  //o(n/2)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
