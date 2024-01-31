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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        ListNode *newList;
        if (list1->val > list2->val)
        {
            newList = list2;
            list2 = list2->next;

        }
        else
        {
            newList = list1;
            list1 = list1->next;
        }
        ListNode *beginNewList = newList;
        
        while(list1 && list2)
        {
            if (list1->val > list2->val)
            {
                newList->next = list2;
                list2 = list2->next;
            }
            else
            {
                newList->next = list1;
                list1 = list1->next;
            }
            newList = newList->next;
        }

        if (list1)
        {
            newList->next = list1;
            list1 = nullptr;
        }
        else
        {
            newList->next = list2;
            list2 = nullptr;
        }

        return beginNewList;
    }
};
