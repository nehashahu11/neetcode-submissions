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
        ListNode* head1 = l1;
        ListNode* head2 = l2;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        int sum = 0;
        while (head1 != NULL || head2 != NULL) {
            int v1 = head1 ? head1->val : 0;
            int v2 = head2 ? head2->val : 0;
            sum = v1 + v2 + carry;

            ListNode* node = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = node;
            curr = curr->next;
            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }
        if (carry) {
            ListNode* node = new ListNode(carry);
            curr->next = node;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
