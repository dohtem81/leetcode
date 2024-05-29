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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int newVal = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0);
        int carry = 0;
        if (newVal > 9)
        {
            carry = 1;
            newVal -= 10;
        }

        ListNode *newNode = new ListNode(newVal);
        ListNode *retVal = newNode;
        
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;

        while (l1 != nullptr || l2 != nullptr)
        {
            newVal = carry + (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0);
            
            if (newVal > 9)
            {
                carry = 1;
                newVal -= 10;
            }
            else carry = 0;          
            
            newNode->next = new ListNode(newVal);
            newNode = newNode->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;            
        }

        if (carry > 0)
        {
            newNode->next = new ListNode(carry);
            newNode = newNode->next;            
        }
        
        return retVal;
    }
};