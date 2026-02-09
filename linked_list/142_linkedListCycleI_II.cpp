//return the starting node of a loop if loop exists, otherwise return null

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //method1: using map data structure
        //time:o(n log(n))
        //space: o(number of nodes in linked list)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        
        map<ListNode*,int>mpp;
        ListNode* temp = head;
        while(temp)
        {    
            if(mpp.contains(temp))
            return temp;
            mpp[temp]=1;
            temp=temp->next;
        }
        return NULL;
    
        
    }
};

//method2: tortoise and hare algorithm
        //time: o(size of linked list)
        //space: o(1)
        class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        
        if(!head || !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    
        
    }
};