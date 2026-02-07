//detect loop in the linked list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //using map data structure
 //time: o(n + 2*log n)
 //space: o(no. of nodes in the linked list)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        map<ListNode*,int>mpp;   //ordered map  
        while(temp)     //o(n)
        {
            if(mpp.contains(temp))   //o(log n)
            return true;  //loop present
            mpp[temp]=1;    //inserting o(log n)
            temp=temp->next;
        }
        return false;  //no lopp
        
    }
};

//using tortoise and hare algo
 //time: o(n)
 //space: o(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast =fast->next->next;
            if(slow==fast) return true;   
        }
        return false;
        
    }
};