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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* p;
        ListNode* q;
        ListNode* evenhead;
        ListNode* oddhead;
        evenhead = head->next;
        oddhead = head;
        p = oddhead;
        q = evenhead;
        while(p->next != NULL && q->next != NULL){
            p->next = q->next;
            p = p->next;
            q->next = p->next;
            q = q->next;
        }
        p->next = evenhead;
        return oddhead;
    }
};