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
    int findLength(ListNode* node){
        int cnt = 0;
        while(node){
            node = node->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = findLength(head);
        if(n==len) return head->next;
        if(n>len) return head;
        n = len-n-1;
        int cnt = 0;
        ListNode* p1=head;
        while(cnt< n){
            p1=p1->next;
            cnt++;
        }
        // if(p1 && p1->next && p1->next->next){
            ListNode* del = p1->next;
            p1->next = p1->next->next;
            delete del;
            // p1->next = p2;
            // p->next=nullptr;
        //}
        return head;
    }
};
