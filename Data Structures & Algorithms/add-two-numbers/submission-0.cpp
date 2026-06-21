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
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carry = 0;
        ListNode* node = new ListNode(-1);
        ListNode* temp = node;
        while(curr1!=nullptr && curr2!=nullptr){
            int val1 = curr1->val;
            int val2 = curr2->val;
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            carry = (sum + carry) / 10;
            temp = temp->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1!=nullptr){
            int sum = curr1->val + carry;
            int digit = sum%10;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            carry = (sum + carry) / 10;
            temp = temp->next;     // missing
            curr1 = curr1->next;   // missing
        }
        while(curr2!=nullptr){
            int sum = curr2->val + carry;
            int digit = sum%10;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            carry = (sum + carry) / 10;
            temp = temp->next;     // missing
            curr2 = curr2->next;   // missing
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        return node->next;
    }
};
