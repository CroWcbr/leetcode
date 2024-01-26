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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* answer = new ListNode();
        ListNode *tmp = answer;
        int tmp_raz = 0;

        while (l1 || l2 || tmp_raz)
        {
            int n = tmp_raz;
            if (l1)
                n += l1->val;
            if (l2)
                n += l2->val;            
            
            if (n >= 10)
            {
                tmp_raz = 1;
                n -= 10;
            }
            else
                tmp_raz = 0;
            
            tmp->next = new ListNode(n);
            tmp = tmp->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        tmp = answer->next;
        delete answer;

        return tmp;
    }
};