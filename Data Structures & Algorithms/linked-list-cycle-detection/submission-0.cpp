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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode *ptr = head;
        std::unordered_set<ListNode*> seen;
        seen.insert(head);
        while (ptr->next) {
            if (seen.find(ptr->next) != seen.end()) return true;
            else { 
                ptr = ptr->next;
                seen.insert(ptr);
            }
        }
        return false;
    }
};
