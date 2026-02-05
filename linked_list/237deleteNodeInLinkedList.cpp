//o(1) time and o(1) space


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        if(node==NULL || node->next==NULL) return;  // is list is empty or next is NULL

        ListNode* temp = node->next;
        node->val = temp->val;                       //copy the next node in the given node and delete next node
        node->next = temp->next;
        delete temp;
        
    }
};