// Time complexity - O(1)
// Space complexity- O(1)
class Solution {
    public:
    void deleteNode(ListNode* node) {
        ListNode* newNode1=node->next;
        ListNode* newNode2=node->next->next;
        
        node->val=newNode1->val;
        node->next=newNode2;
        delete newNode1;
    }
};