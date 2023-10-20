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
        ListNode*temp = head;
        while(temp->next != NULL and temp->next->next != NULL){
            ListNode*temp2 = temp;
            while(temp2->next->next != NULL){
                temp2=temp2->next;
            }
            temp2->next->next = temp->next;
        temp->next = temp2->next;
        temp2->next = NULL;
        temp = temp->next->next;
        }
        
        
    }
};