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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp;
        
        tmp = head;
        int len = 0;
        for(; tmp; ++len)
            tmp = tmp->next;

        if (len == n)
        {
           tmp = head;
           head = head->next;
           delete(tmp);
        }
        else
        {
            tmp = head;
            int i = 0;
            for (;i < len - n - 1; ++i)
                tmp = tmp->next;

            if (!tmp)
                return nullptr;

            ListNode* tmp_del = tmp->next;
            if (tmp_del)
                tmp->next = tmp_del->next;
            else
                tmp->next = nullptr;
            if (tmp_del)
                delete (tmp_del);
        }
 
        return head;
    }
};