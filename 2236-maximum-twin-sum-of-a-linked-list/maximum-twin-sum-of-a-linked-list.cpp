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
    int pairSum(ListNode* head) {
        int ans = 0;
        stack<int> st;
        ListNode* p = head;
        while(p != NULL){
            st.push(p->val); p = p->next;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        p = head;
        ListNode* mid = slow;
        while(p != mid){
            int a = p->val;
            int b = st.top();
            ans = max(ans, a+b);
            st.pop();
            p = p->next;
        }
        return ans;
    }
};