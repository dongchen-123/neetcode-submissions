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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        else if(!head->next->next) {
            ListNode* new_head = head->next;
            head->next->next = head;
            head->next = nullptr;
            return new_head;
        }
        else {
            ListNode *tmp, *tmp_prev, *tmp_next;
            tmp_prev = nullptr;
            tmp = head;
            tmp_next = head->next;
            while (tmp_next) {
                tmp->next = tmp_prev;
                tmp_prev = tmp;
                tmp = tmp_next;
                tmp_next = tmp_next->next;
            }
            tmp->next = tmp_prev;
            return tmp;
        }
    }
};
