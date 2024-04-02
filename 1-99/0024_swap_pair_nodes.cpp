// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* tmp_head = head;
        ListNode* prev = nullptr;
        head = head->next;
        while (tmp_head && tmp_head->next)
        {
            ListNode* first = tmp_head;
            ListNode* second = tmp_head->next;
            ListNode* third = tmp_head->next->next;

            second->next = first;
            first->next = third;
            if (prev)
                prev->next = second;

            tmp_head = third; 
            prev = first;
        }

        return head;
    }
};