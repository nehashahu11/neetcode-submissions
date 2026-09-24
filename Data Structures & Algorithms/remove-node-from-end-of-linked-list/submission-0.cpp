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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count =0;
        ListNode* temp = head;
        while(temp != nullptr){
             count ++;
             temp= temp->next;
        }
        if (count == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode *prev = head;
        int m = count-n;
        for(int i =0; i < m-1; i++){
            prev = prev->next;
        }
        ListNode* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;

    return head;    
    }
};
