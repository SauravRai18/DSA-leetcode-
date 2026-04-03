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
    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        slow->next = nullptr;

        while(curr){

            ListNode* next = curr->next;
            curr->next = prev;
            
            prev = curr;

            curr = next;
        }

        ListNode* first = head;
        ListNode* sec = prev;

        while(sec){
            ListNode* temp1 = first->next;
            ListNode* temp2 = sec->next;

            first->next = sec;
            sec->next = temp1;

            first = temp1;
            sec = temp2;
        }
        
    }
};